#include<bits/stdc++.h>
using namespace std;
bool is_tongyice(string x,string y){
	char a=x[2],b=y[2];
	bool lra=0,lrb=0;
	if(a=='A'||a=='B'||a=='C') lra=0;
	else lra=1;
	if(b=='A'||b=='B'||b=='C') lrb=0;
	else lrb=1;
	
	return lra==lrb;
} 
bool is_xianglin(string x,string y){
	char a=x[2],b=y[2];
	if((a=='F'&&b=='D')||(a=='D'&&b=='F')||(a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')) return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c[3]={},s[3]={};
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]) cout<<1;
	else cout<<0;
	if(c[1]==c[2]&&s[1][0]==s[2][0]&&s[1][1]==s[2][1]) cout<<1;
	else cout<<0;
	if(c[1]==c[2]&&s[1][0]==s[2][0]&&s[1][1]==s[2][1]&&is_tongyice(s[1],s[2])) cout<<1;
	else cout<<0; 
	if(c[1]==c[2]&&s[1][0]==s[2][0]&&s[1][1]==s[2][1]&&is_xianglin(s[1],s[2])) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
