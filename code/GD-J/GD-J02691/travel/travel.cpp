#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f=1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0,f=0;
	if((f==1)&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else cout<<0,f=0;
	if(b[2]>d[2]) swap(b[2],d[2]);
	if((f==1)&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='A'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')))
		cout<<1;
	else cout<<0,f=0;
	if((f==1)&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')))
		cout<<1;
	else cout<<0,f=0;
	return 0;
}
