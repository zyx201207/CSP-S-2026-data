#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	freopen("string3.in","r",stdin);
	freopen("string3.out","w",stdout);
	cin>>n;
	long long ans=0;
	long long k = 0;
	for(long long i = 1;i<=n;i++)
	{
		long long a,c;
		cin>>a;
		char b;
		cin>>b;
		for(long long j = k+1;j<=k+a;j++)
		{
			s[j]=b;
			c=j;
		}
		k=c;
	} 
	for(long long i = 1;i<=k/2;i++)
	{
		if(s[i]!=s[k-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
} 
