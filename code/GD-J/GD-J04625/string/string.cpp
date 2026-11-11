#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1100100];
string s[1100100],ss="";
int  main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		for(long j=1;j<=a[i];j++)
		{
			ss+=s[i];
		}
	}
	long long r=ss.size()-1,ans=0;
	for(long long i=0;i<=r/2;i++)
	{
		if(ss[i]!=ss[r-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
 } 
