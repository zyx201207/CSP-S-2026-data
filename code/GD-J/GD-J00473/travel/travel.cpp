#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string c1,s1,c2,s2;
char seat1[3]={'A','B','C'},seat2[2]={'D','F'};
bool s[4]={0};
void inpangbian(char a,char b,bool x,bool y){
	if((a=='D'||b=='D')&&x==1&&y==1) s[3]=1;
	if(a=='B'||b=='B'){
		if(a=='B'){
			if(b=='A'||b=='C') s[3]=1;
		}
		if(b=='B'){
			if(a=='A'||a=='C') s[3]=1;
		}
	}
}
void intongce(char a,char b){
	bool x=0,y=0;
	for(int i=0;i<=2;i++){
		if(seat1[i]==a) x=1;
		else if(seat1[i]==b) y=1;
	}
	if(x==y) s[2]=1;
	else{
		x=0;
		y=0;
	}
	for(int i=0;i<=1;i++){
		if(seat2[i]==a) x=1;
		else if(seat2[i]==b) y=1;
	}
	if(x==y) s[2]=1;
	inpangbian(a,b,x,y);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			s[1]=1;
			intongce(s1[2],s2[2]);
		}
	}
	for(int i=0;i<=3;i++) cout<<s[i];
	return 0;
}
