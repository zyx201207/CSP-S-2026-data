#include <bits/stdc++.h>
using namespace std;
int n,x;
string s,y,m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>s;
		for(int j=1;j<=x;j++)
		{
			y=y+s;
		}
	}
	for(int i=y.length();i>=0;i--)
	{
		m=m+y[i];
	}
	if(y==m)
	{
		cout<<"0";
	}
	else
	{
		cout<<y.size()/2;
	}
	return 0;
}
