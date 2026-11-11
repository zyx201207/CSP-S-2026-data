#include<bits/stdc++.h>
using namespace std;
int main( )
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	string z1=b.substr(0,2),z2=d.substr(0,2);
	if(a==c) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(z1==z2) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	bool f1=true,f2=true;
	if(b[2]=='D'||b[2]=='E') f1=false;
	if(d[2]=='D'||d[2]=='E') f2=false;
	if(f1==f2) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs((int)b[2]-(int)d[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
