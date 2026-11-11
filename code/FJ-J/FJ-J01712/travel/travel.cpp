#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string ans="";
	if(a==c)
	{
		ans=ans+"1";
	}
	else
	{
		ans=ans+"0";
	}
	if(b[0]==d[0]&&b[1]==d[1]&&ans[0]=='1')
	{
		ans=ans+"1";
	}
	else
	{
		ans=ans+"0";
	}
	if(ans[1]=='1'&&((b[2]<='C')==(d[2]<='C')))
	{
		ans=ans+"1";
	}
	else
	{
		ans=ans+"0";
	}
	int x=b[2],y=d[2];
	if(ans[2]=='1'&&(x+1==y||y+1==x))
	{
		ans=ans+"1";
	}
	else
	{
		ans=ans+"0";
	}
	cout<<ans;
	return 0;
 } 
