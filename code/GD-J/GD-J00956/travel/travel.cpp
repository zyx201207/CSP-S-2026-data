#include<bits/stdc++.h>
using namespace std;
int a,b,s,s0,xx,yy;
string s1,s2;
bool c1=0,c2=0,c3=0;
char x,y;
int main(){
	freopen("travel.in","r",stdin);//////////////////////////////////
	freopen("travel.out","w",stdout);////////////////////////////////
	cin>>a>>s1>>b>>s2;
	s=(s1[0]-'0')*10+(s1[1]-'0');
	s0=(s2[0]-'0')*10+(s2[1]-'0');
	x=s1[2];
	y=s2[2];
	if(x=='A'||x=='B'||x=='C'){
		xx=1;
	}
	if(y=='A'||y=='B'||y=='C'){
		yy=1;
	}
	if(a==b){
		cout<<1;
		c1=1;
	}
	else cout<<0;
	if(c1&&s==s0){
		c2=1;
		cout<<1;
	}
	else cout<<0;
	if(c2&&xx==yy){
		c3=1;
		cout<<1;
	}
	else cout<<0;
	if(c3&&abs(x-y)==1){
		cout<<1;
	}
	else cout<<0;
} 
