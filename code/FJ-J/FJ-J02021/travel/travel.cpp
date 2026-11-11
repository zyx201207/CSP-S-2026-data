#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a[1]==c[1])
	cout<<1;
	else
	{
		cout<<"0000";
		exit(0);
	}
	if(b[1]==d[1])
	cout<<1;
	else
	{
		cout<<"000";
		exit(0);
	}
	if((b[2]=='F'&&d[2]=='D')||(d[2]=='F'&&b[2]=='D')||(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'))
	cout<<1;
	else
	{
		cout<<"00";
		exit(0);
	}
	if(b[2]>='A'&&b[2]<='C')
	{
		if(b[2]=='B'||d[2]=='B')
			cout<<1;
		else
			cout<<"0";
		exit(0);
	}
	else
	cout<<"0";
	return 0;
}