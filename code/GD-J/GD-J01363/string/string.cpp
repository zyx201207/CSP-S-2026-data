#include<bits/stdc++.h>
using namespace std;

long long sum,n,x,cnt;
string s,c;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x>>c;
		for(long long j=1;j<=x;j++)
		{
			s=s+c;
		}
		sum+=x;
	}
	for(long long i=0;i<sum/2;i++)
	{
		long long p=sum-i-1;
		if(s[i]!=s[p]) cnt++;
	}
	cout<<cnt;
	
	return 0;
}
