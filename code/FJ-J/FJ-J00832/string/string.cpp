#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,size=0,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long m;
		char s1;
		cin>>m>>s1;
		for(long long j=1;j<=m;j++)
		{
			s=s+s1;
			size++;
		}
	}
	for(long long i=0;i<size/2;i++)
	{
		if(s[i]!=s[size-i-1])
		{				
			ans++;			
		}		
	}
	cout<<ans;
	return 0;
}