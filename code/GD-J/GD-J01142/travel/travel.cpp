#include<bits/stdc++.h>
using namespace std;
string a,x,b,y;
char s1,s2;
long long vx,vy,p[6][19];
bool f(char a,int x,char b,int y){
	if(a=='C'&&b=='D')return 0;
	if(abs(a-b)==1&&x==y)return 1;
	if(a==b&&abs(x-y)==1)return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>x>>b>>y;
	if(a!=b){cout<<"0000";return 0;}
	if(a==b)cout<<"1";
	vx=(x[0]-'0')*10+x[1]-'0';
	vy=(y[0]-'0')*10+y[1]-'0';
	s1=x[2],s2=y[2];
	if(vx==vy)cout<<"1";
	else cout<<"0";
	if(vx==vy&&s1<'D'&&s2<'D'||vx==vy&&s1>'C'&&s2>'C')cout<<"1";
	else cout<<"0";
	if(f(s1,vx,s2,vy))cout<<"1";
	else cout<<"0";
	return 0;
}
