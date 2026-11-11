//nwn
#include <bits\stdc++.h>
using namespace std;
int ma,mc;
string bt,bn;
int kkl,kkm;
bool pl,ps;
bool mma[4]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ma>>bt;
	cin>>mc>>bn;
	kkl=bt[2]-'A';
	kkm=bn[2]-'A';
	if(kkl==0||kkl==1||kkl==2){
		pl=0;
	}
	else{
		pl=1;
	}
	
	if(kkm==0||kkm==1||kkm==2){
		ps=0;
	}
	else{
		ps=1;
	}
	//哎呦我去
	
	if(kkl+1==kkm||kkl-1==kkm){//相邻？ 
		mma[3]=1;
	}
	
	if(ps==pl){
		mma[2]=1;
	}
	else{
		mma[2]=0;
		mma[3]=0;
	}
	
	if(bt[0]==bn[0]&&bt[1]==bn[1]){//同一排？ 
		mma[1]=1;
	}
	else{
		mma[1]=0;
		mma[2]=0;
		mma[3]=0;
	}
	
	if(ma==mc){//同一车厢？ 
		mma[0]=1;
	}
	else{
		mma[0]=0;
		mma[1]=0;
		mma[2]=0;
		mma[3]=0;		
	}
	for(int i=0;i<4;i++){
		cout<<mma[i]<<' ';
	}
	return 0;
}
/*
Only pilah like
nave beave hanm
when I wife you
when I wife you
dance all niged
nave beave hanm
when I wife you
when I wife you
[结晶生成中]
X X XXX
O O OOO
X X X X

*/
