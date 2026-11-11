#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
void d(char x,char y){
	if(x=='A'&&y=='B')t=1;
	if(x=='B'&&y=='A')t=1;
	if(x=='B'&&y=='C')t=1;
	if(x=='C'&&y=='B')t=1;
}
bool s(char x,char y){
	if(x<='C'&&y<='C'){
		d(x,y);
		return 1;
	}
	if(x=='F'&&y=='D'){
		t=1;
		return 1;
	}
	if(x=='D'&&y=='F'){
		t=1;
		return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	string x,y;
	x+=s1[0];
	x+=s1[1];
	y+=s2[0];
	y+=s2[1];
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&x==y)cout<<1;
	else cout<<0;
	if(c1==c2&&x==y&&s(s1[2],s2[2]))cout<<1;
	else cout<<0;
	if(c1==c2&&x==y&&s(s1[2],s2[2])&&t==1)cout<<1;
	else cout<<0;
	return 0;
}
