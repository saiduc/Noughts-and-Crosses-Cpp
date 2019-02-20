#include <iostream>
#include <ctime>
using namespace std;
void print(char board[3][3])	//prints the grid
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"["<<board[i][j]<<"] \t";
		}
		cout<<endl;
	}
}
bool startfirst(string oddoreven)
{
	srand(time(0));
	int random=rand()%10+1;
	int remainder=random%2;
	//cout<<random<<" "<<remainder<<endl;
	//put in for testing^
	if(((oddoreven=="odd")&&(remainder==1))||((oddoreven=="even")&&(remainder==0)))
	{
		cout<<"the player will start first"<<endl;
		return false;
	}
	else
	{
		cout<<"the computer will start first"<<endl;
		return true;
	}
}
bool checkvalid(char board[3][3],char move)
{
	if(move=='a')
	{
		if((board[0][0]=='X')||(board[0][0]=='O')){return false;}
		else{return true;}
	}
	if(move=='b')
	{
		if((board[0][1]=='X')||(board[0][1]=='O')){return false;}
		else{return true;}
	}
	if(move=='c')
	{
		if((board[0][2]=='X')||(board[0][2]=='O')){return false;}
		else{return true;}
	}
	if(move=='d')
	{
		if((board[1][0]=='X')||(board[1][0]=='O')){return false;}
		else{return true;}
	}
	if(move=='e')
	{
		if((board[1][1]=='X')||(board[1][1]=='O')){return false;}
		else{return true;}
	}
	if(move=='f')
	{
		if((board[1][2]=='X')||(board[1][2]=='O')){return false;}
		else{return true;}
	}
	if(move=='g')
	{
		if((board[2][0]=='X')||(board[2][0]=='O')){return false;}
		else{return true;}
	}
	if(move=='h')
	{
		if((board[2][1]=='X')||(board[2][1]=='O')){return false;}
		else{return true;}
	}
	if(move=='i')
	{
		if((board[2][2]=='X')||(board[2][2]=='O')){return false;}
		else{return true;}
	}
	if((move!='a')&&(move!='b')&&(move!='c')&&(move!='d')&&(move!='e')&&(move!='g')&&(move!='h')&&(move!='i'))
	{
		return false;
	}
}
void playermakemove(char (&board)[3][3])
{
	char letter;
	bool validmove=false;
	while(!validmove)
	{
		cout<<"please type a letter to make a move"<<endl;
		cin>>letter;
		validmove=checkvalid(board,letter);
		if(!validmove)
		{
			cout<<"move not valid, please enter another one:"<<endl;
		}
	}
	if(letter=='a'){board[0][0]='O';}
	if(letter=='b'){board[0][1]='O';}
	if(letter=='c'){board[0][2]='O';}
	if(letter=='d'){board[1][0]='O';}
	if(letter=='e'){board[1][1]='O';}
	if(letter=='f'){board[1][2]='O';}
	if(letter=='g'){board[2][0]='O';}
	if(letter=='h'){board[2][1]='O';}
	if(letter=='i'){board[2][2]='O';}
	cout<<"you played:"<<endl;
	print(board);
}
bool cancpuwin(char board[3][3],int &winh0,int &winh1,int &winh2,int &winv0,int &winv1,int &winv2,int &windr,int &windl)
{
	int numxh0=0;
	int numxh1=0;
	int numxh2=0;
	int numxv0=0;
	int numxv1=0;
	int numxv2=0;
	int numxdr=0;
	int numxdl=0;
	int numspaceh0=0;
	int numspaceh1=0;
	int numspaceh2=0;
	int numspacev0=0;
	int numspacev1=0;
	int numspacev2=0;
	int numspacedr=0;
	int numspacedl=0;
	for(int j=0; j<3; j++)
	{
		if(board[0][j]=='X'){numxh0=numxh0+1;}
		if((board[0][j]!='O')&&(board[0][j]!='X')){numspaceh0=numspaceh0+1;}
	}
	for(int j=0; j<3; j++)
	{
		if(board[1][j]=='X'){numxh1=numxh1+1;}
		if((board[1][j]!='O')&&(board[1][j]!='X')){numspaceh1=numspaceh1+1;}
	}
	for(int j=0; j<3; j++)
	{
		if(board[2][j]=='X'){numxh2=numxh2+1;}
		if((board[2][j]!='O')&&(board[2][j]!='X')){numspaceh2=numspaceh2+1;}
	}
	for(int i=0; i<3; i++)
	{
		if(board[i][0]=='X'){numxv0=numxv0+1;}
		if((board[i][0]!='O')&&(board[i][0]!='X')){numspacev0=numspacev0+1;}
	}
	for(int i=0; i<3; i++)
	{
		if(board[i][1]=='X'){numxv1=numxv1+1;}
		if((board[i][1]!='O')&&(board[i][1]!='X')){numspacev1=numspacev1+1;}
	}
	for(int i=0; i<3; i++)
	{
		if(board[i][2]=='X'){numxv2=numxv2+1;}
		if((board[i][2]!='O')&&(board[i][2]!='X')){numspacev2=numspacev2+1;}
	}
	for(int j=0; j<3; j++)
	{
		if(board[j][j]=='X'){numxdr=numxdr+1;}
		if((board[j][j]!='O')&&(board[j][j]!='X')){numspacedr=numspacedr+1;}
	}
	for(int j=0; j<3; j++)
	{
		if(board[j][((j*-1)+2)]=='X'){numxdl=numxdl+1;}
		if((board[j][((j*-1)+2)]!='O')&&(board[j][((j*-1)+2)]!='X')){numspacedl=numspacedl+1;}
	}
	if((numxh0==2)&&(numspaceh0==1)){winh0=1;
		return true;}
	else if((numxh1==2)&&(numspaceh1==1)){winh1=1;
		return true;}
	else if((numxh2==2)&&(numspaceh2==1)){winh2=1;
		return true;}
	else if((numxv0==2)&&(numspacev0==1)){winv0=1;
		return true;}
	else if((numxv1==2)&&(numspacev1==1)){winv1=1;
		return true;}
	else if((numxv2==2)&&(numspacev2==1)){winv2=1;
		return true;}
	else if((numxdr==2)&&(numspacedr==1)){windr=1;
		return true;}
	else if((numxdl==2)&&(numspacedl==1)){windl=1;
		return true;}
	else{return false;}
}
bool canplayerwin(char board[3][3], int &ph0,int &ph1,int &ph2,int &pv0, int &pv1, int &pv2, int &pdr, int &pdl)
{
	int numoh0=0;
	int numoh1=0;
	int numoh2=0;
	int numov0=0;
	int numov1=0;
	int numov2=0;
	int numodr=0;
	int numodl=0;
	int numspaceph0=0;
	int numspaceph1=0;
	int numspaceph2=0;
	int numspacepv0=0;
	int numspacepv1=0;
	int numspacepv2=0;
	int numspacepdr=0;
	int numspacepdl=0;
	for(int j=0; j<3; j++)
	{
		if(board[0][j]=='O'){numoh0=numoh0+1;}
		if((board[0][j]!='O')&&(board[0][j]!='X')){numspaceph0=numspaceph0+1;}
	}
	for(int j=0; j<3; j++)
	{
		if(board[1][j]=='O'){numoh1=numoh1+1;}
		if((board[1][j]!='O')&&(board[1][j]!='X')){numspaceph1=numspaceph1+1;}
		//cout<<numoh1<<numspaceph1<<endl;//test
	}
	for(int j=0; j<3; j++)
	{
		if(board[2][j]=='O'){numoh2=numoh2+1;}
		if((board[2][j]!='O')&&(board[2][j]!='X')){numspaceph2=numspaceph2+1;}
	}
	for(int i=0; i<3; i++)
	{
		if(board[i][0]=='O'){numov0=numov0+1;}
		if((board[i][0]!='O')&&(board[i][0]!='X')){numspacepv0=numspacepv0+1;}
	}
	for(int i=0; i<3; i++)
	{
		if(board[i][1]=='O'){numov1=numov1+1;}
		if((board[i][1]!='O')&&(board[i][1]!='X')){numspacepv1=numspacepv1+1;}
		//cout<<numov1<<numspacepv1<<endl;//test
	}
	for(int i=0; i<3; i++)
	{
		if(board[i][2]=='O'){numov2=numov2+1;}
		if((board[i][2]!='O')&&(board[i][2]!='X')){numspacepv2=numspacepv2+1;}
	}
	for(int j=0; j<3; j++)
	{
		if(board[j][j]=='O'){numodr=numodr+1;}
		if((board[j][j]!='O')&&(board[j][j]!='X')){numspacepdr=numspacepdr+1;}
	}
	for(int j=0; j<3; j++)
	{
		if(board[j][((j*-1)+2)]=='O'){numodl=numodl+1;}
		if((board[j][((j*-1)+2)]!='O')&&(board[j][((j*-1)+2)]!='X')){numspacepdl=numspacepdl+1;}
	}
	if((numoh0==2)&&(numspaceph0==1)){ph0=1;cout<<"a"<<endl;
	return true;}
	else if((numoh1==2)&&(numspaceph1==1)){ph1=1;//cout<<"a"<<endl;
	return true;}
	else if((numoh2==2)&&(numspaceph2==1)){ph2=1;//cout<<"a"<<endl;
	return true;}
	else if((numov0==2)&&(numspacepv0==1)){pv0=1;//cout<<"a"<<endl;
	return true;}
	else if((numov1==2)&&(numspacepv1==1)){pv1=1;//cout<<"a"<<endl;
	return true;}
	else if((numov2==2)&&(numspacepv2==1)){pv2=1;//cout<<"a"<<endl;
	return true;}
	else if((numodr==2)&&(numspacepdr==1)){pdr=1;//cout<<"a"<<endl;
	return true;}
	else if((numodl==2)&&(numspacepdl==1)){pdl=1;//cout<<"a"<<endl;
	return true;}
	else{cout<<"b"<<endl; return false;}
}
void computermakemove(char (&board)[3][3])
{
	int h0=0;
	int h1=0;
	int h2=0;
	int v0=0;
	int v1=0;
	int v2=0;
	int dr=0;
	int dl=0;
	bool caniwin=cancpuwin(board,h0,h1,h2,v0,v1,v2,dr,dl);
	if(caniwin==true)
	{
		//cout<<"first"<<endl;//first
		if(h0==1)
		{
			for(int j=0; j<3; j++)
			{
				if(!(board[0][j]=='X')){board[0][j]='X';}
			}
		}
		if(h1==1)
		{
			for(int j=0; j<3; j++)
			{
				if(board[1][j]!='X'){board[1][j]='X';}
			}
		}
		if(h2==1)
		{
			for(int j=0; j<3; j++)
			{
				if(board[2][j]!='X'){board[2][j]='X';}
			}
		}
		if(v0==1)
		{
			for(int i=0; i<3; i++)
			{
				if(board[i][0]!='X'){board[i][0]='X';}
			}
		}
		if(v1==1)
		{
			for(int i=0; i<3; i++)
			{
				if(board[i][1]!='X'){board[i][1]='X';}
			}
		}
		if(v2==1)
		{
			for(int i=0; i<3; i++)
			{
				if(board[i][2]!='X'){board[i][2]='X';}
			}
		}
		if(dr==1)
		{
			for(int j=0; j<3; j++)
			{
				if(board[j][j]!='X'){board[j][j]='X';}
			}
		}
		if(dl==1)
		{
			//cout<<"it is"<<endl;
			for(int j=0; j<3; j++)
			{
				if(board[j][((j*-1)+2)]!='X'){board[j][((j*-1)+2)]='X';}
			}
		}
	}
	else if(!caniwin)
	{
		//cout<<"second"<<endl;//second
		int hp0=0;
		int hp1=0;
		int hp2=0;
		int vp0=0;
		int vp1=0;
		int vp2=0;
		int drp=0;
		int dlp=0;
		bool cantheywin=canplayerwin(board,hp0,hp1,hp2,vp0,vp1,vp2,drp,dlp);
		if(cantheywin)
		{
			//cout<<"third"<<endl;//third
			if(hp0==1)
			{
				for(int j=0; j<3; j++)
				{
					if(board[0][j]!='O'){board[0][j]='X';}
				}
			}
			if(hp1==1)
			{
				for(int j=0; j<3; j++)
				{
					if(board[1][j]!='O'){board[1][j]='X';}
				}
			}
			if(hp2==1)
			{
				for(int j=0; j<3; j++)
				{
					if(board[2][j]!='O'){board[2][j]='X';}
				}
			}
			if(vp0==1)
			{
				for(int i=0; i<3; i++)
				{
					if(board[i][0]!='O'){board[i][0]='X';}
				}
			}
			if(vp1==1)
			{
				for(int i=0; i<3; i++)
				{
					if(board[i][1]!='O'){board[i][1]='X';}
				}
			}
			if(vp2==1)
			{
				for(int i=0; i<3; i++)
				{
					if(board[i][2]!='O'){board[i][2]='X';}
				}
			}
			if(drp==1)
			{
				for(int j=0; j<3; j++)
				{
					if(board[j][j]!='O'){board[j][j]='X';}
				}
			}
			if(dlp==1)
			{
				for(int j=0; j<3; j++)
				{
					if(board[j][((j*-1)+2)]!='O'){board[j][((j*-1)+2)]='X';}
				}
			}
		}
		if(cantheywin==false)
		{
			//cout<<"fourth"<<endl;//fourth
			int positionx;
			int positiony;
			int done=0;
			while(done==0)
			{
				positionx=rand()%3;
				positiony=rand()%3;
				if((board[positiony][positionx]!='X')&&(board[positiony][positionx]!='O'))
				{
					board[positiony][positionx]='X';
					done=1;
				}
			}
		}
	}
	cout<<"computer played:"<<endl;
	print(board);
}
void firstmove(char (&board)[3][3],bool startfirst)
{
	if(startfirst)
	{
		board[1][1]='X';
		cout<<"the computer played:"<<endl;
		print(board);
	}
	if(!startfirst)
	{
		playermakemove(board);
		if(board[1][1]!='O')
		{
			board[1][1]='X';
		}
		else
		{
			board[(((rand()%10)+1)%2)*2][(((rand()%10)+1)%2)*2]='X';
		}
		cout<<"the computer played:"<<endl;
		print(board);
	}
}
bool checkifwon(char board[3][3])
{
	int horwin=0,vertwin=0,diagwin=0;
	for(int i=0; i<3; i++)
	{
		if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2]))
		{
			horwin=1;
		}
	}
	for(int j=0; j<3; j++)
	{
		if((board[0][j]==board[1][j])&&(board[1][j]==board[2][j]))
		{
			vertwin=1;
		}
	}
	if(((board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))||((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])))
	{
		diagwin=1;
	}
	if((horwin==1)||(vertwin==1)||(diagwin==1))
	{
		return true;
	}
	else
	{
		return false;
	}

}
int main()
{
	char grid[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
	print(grid);
	cout<<"welcome to noughts and crosses, you will be O and the computer will be X"<<endl;
	cout<<"to decide who shall go first, guess odd or even?"<<endl;
	string answer;
	cin>>answer;
	bool start=startfirst(answer);
	firstmove(grid,start);
	bool won=false;
	int counter=0;
	while(!won)
	{
		counter=0;
		//cout<<counter<<endl;
		playermakemove(grid);
		won=checkifwon(grid);
		if(!won)
		{
			computermakemove(grid);
			won=checkifwon(grid);
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if((grid[i][j]=='X')||(grid[i][j]=='O'))
				{
					counter++;
				}
			}
		}
		if(counter==9){won=true;}
	}
	cout<<"GAME OVER"<<endl;
}
