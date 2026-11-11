#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string a="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long b;
		cin>>b;
		char d;
		cin>>d;
		for(int j=1;j<=b;j++)
		{
			a+=d;
		}
	}
	string m="";
	for(int i=0;i<=floor(a.size()/2)-1;i++)
	{
		m+=a[i];
	}
	string g="";
	for(int i=a.size()-1;i>=ceil(a.size()/2);i--)
	{
		g+=a[i];
	}
	long long cnt=0;
	for(int i=0;i<=floor(a.size()/2)-1;i++)
	{
		if(g[i]!=m[i])cnt++;
	}
	cout<<cnt;
	return 0;
 } 
