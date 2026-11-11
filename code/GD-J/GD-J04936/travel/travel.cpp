#include<bits/stdc++.h>
using namespace std;
string x, y, n, m;
int f(string s){
	if(s[2]=='A')return 1;
	if(s[2]=='B')return 2;
	if(s[2]=='C')return 3;
	if(s[2]=='D')return 4;
	if(s[2]=='F')return 5;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>x>>y>>n>>m;
	bool OK1=false;
	bool OK2=false;
	if(x==n){
		cout<<1;
		OK1=true;
	}else{
		cout<<0;
	}
	if(y[0]==m[0]&&y[1]==m[1]&&OK1){
		cout<<1;
		OK2=true;
	}else{
		cout<<0;
	}
	int a=f(y);
	int b=f(m);
	bool OK3=false;
	if((a>=1&&a<=3)&&(b>=1&&b<=3)&&OK2){
		cout<<1;
		OK3=true;
	}else if((a>=4&&a<=5)&&(b>=4&&a<=5)&&OK2){
		cout<<1;
		OK3=true;
	}else{
		cout<<0;
	}
	int c=abs(a-b);
	if(c==1&&OK3){
		cout<<1<<"\n";
	}else{
		cout<<0<<"\n";
	}
	return 0;
}
