#include<bits/stdc++.h>
using namespace std;
char a[10000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	long long x;
	char b;
	for(long long i=0;i<n;i++)
	{
		cin>>x>>b;
		for(long long j=cnt;j<x+cnt;j++)
		{
			a[j]=b;
		}
		cnt+=x;
	}
	long long ans=0; 
	for(long long i=0;i<cnt/2;i++)
	{
		if(a[cnt-i-1]!=a[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
