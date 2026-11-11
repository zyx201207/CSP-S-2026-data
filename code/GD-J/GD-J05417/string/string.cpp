#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,ans=0;
	string s;
	long long sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long m;
		cin>>m;
		sum+=m;
		string c;
		cin>>c;
		for(long long j=1;j<=m;j++)
		{
			s+=c;
		}
	}
	sum--;
	for(long long i=0;i<(sum+1)/2;i++)
	{
		if(s[i]!=s[sum])
		{
			ans++;
		}
		sum--;
	}
	cout<<ans;
	return 0;
} 
