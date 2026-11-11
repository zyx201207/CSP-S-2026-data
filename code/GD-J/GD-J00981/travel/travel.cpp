#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool mz()
{
	if(c[2]=='D'&&d[2]=='F') return 1;
	if(c[2]=='F'&&d[2]=='D') return 1;
	if(c[2]!='D'&&c[2]!='F'&&d[2]!='D'&&d[2]!='F') return 1;
	return 0; 
}
bool xl()
{
	if(c[2]=='A'&&d[2]=='B') return 1;
	if(c[2]=='B'&&d[2]=='A') return 1;
	if(c[2]=='B'&&d[2]=='C') return 1;
	if(c[2]=='C'&&d[2]=='B') return 1;
	if(c[2]=='D'&&d[2]=='F') return 1;
	if(c[2]=='F'&&d[2]=='D') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b) cout<<1;
	else cout<<0;
	if(a==b&&c[0]==d[0]&&c[1]==d[1]) cout<<1;
	else cout<<0;
	if(a==b&&c[0]==d[0]&&c[1]==d[1]&&mz()) cout<<1;
	else cout<<0;
	if(a==b&&c[0]==d[0]&&c[1]==d[1]&&xl()) cout<<1;
	else cout<<0;
	return 0;
}
