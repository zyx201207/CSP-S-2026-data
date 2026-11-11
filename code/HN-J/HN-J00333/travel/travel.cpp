#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	int x=(a[0]-'0')*10+a[1]-'0';
	int y=(b[0]-'0')*10+b[1]-'0';
	if(x==y) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(a[2]<='C'&&b[2]<='C')
	{
		cout<<1;
		if(a[2]==b[2]+1||a[2]==b[2]-1) cout<<1;
		else cout<<0;
	}
	else if(a[2]>='D'&&b[2]>='D') cout<<"11";
	else cout<<"00";
}

