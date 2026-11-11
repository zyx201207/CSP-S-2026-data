#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rbox,xbox;
	int lie1,lie2;
	string rpos,xpos;
	cin >> rbox >> rpos >> xbox >> xpos;
	lie1=rpos[0]-48;
	int tmp1=rpos[1]-48;
	int fuck;
	if (lie1 !=0){
		fuck =lie1 *10;
		fuck+=tmp1;
	}else{
		fuck = tmp1;
	}
	lie2=xpos[0]-48;
	int tmp2=xpos[1]-48;
	int fucke;
	if (lie2 !=0){
		fucke =lie2 *10;
		fucke=tmp2;
	}else{
		fucke = tmp2;
	}
	char r=rpos[2],x=xpos[2];
	
	int a=0,b=0,c=0,d=0;
	if(fuck==fucke){
	b=1;
	if(r=='A'&&x=='B')c=1;
	if(r=='A'&&x=='C')c=1;
	if(r=='B'&&x=='A')c=1;
	if(r=='B'&&x=='C')c=1;
	if(r=='C'&&x=='B')c=1;
	if(r=='C'&&x=='A')c=1;
	if(r=='D'&&x=='F')c=1;
	if(r=='F'&& x=='D')c=1;
	if(rbox==xbox)a=1;
	if(r!='C'&&r+1==x)d=1;
	cout<< a <<b << c << d;
	return 0;}
}
