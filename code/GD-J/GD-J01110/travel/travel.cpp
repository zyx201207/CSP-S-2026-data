#include<bits/stdc++.h>
using namespace std;
int a,c;
string u,v;
char b,d;
int x,y;
bool ce(char x,char y)
{
	if(x=='F'||x=='D')
	{
		if(y=='F'||y=='D') return 1;
		return 0;
	}
	else
	{
		if(y=='A'||y=='B'||y=='C') return 1;
		return 0;
	}
}
bool xl(char x,char y)
{
	if(x=='F'&&y=='D') return 1;
	if(x=='D'&&y=='F') return 1;
	if(x=='C'&&y=='B') return 1;
	if(x=='B'&&(y=='C'||y=='A')) return 1;
	if(x=='A'&&y=='B') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);//¸Ä 
	freopen("travel.out","w",stdout);//¸Ä 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>u>>c>>v;
	for(int i=0;i<u.size()-1;i++)
		x=x*10+(u[i]-'0');
	for(int i=0;i<v.size()-1;i++)
		y=y*10+(v[i]-'0');
	b=u[u.size()-1],d=v[v.size()-1];
	if(a==c) cout<<"1";
	else cout<<"0";
	
	if(a==c&&x==y) cout<<"1";
	else cout<<"0";
	
	if(a==c&&x==y&&ce(b,d)) cout<<"1";
	else cout<<"0";
	
	if(a==c&&x==y&&ce(b,d)&&xl(b,d)) cout<<"1";
	else cout<<"0";
	
	return 0;	
} 
