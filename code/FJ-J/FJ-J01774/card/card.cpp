#include<bits/stdc++.h>
using namespace std;
long long a[1000005],s[1000005];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long l=i;
		long long e[50005]={0},k[50005]={0};
		for(long long j=i;j<=n;j++)
		{
			e[a[j]]++;
			if(e[a[j]]>1)
			{
				l=j;
			}
		}
		for(long long j=l;j<=n;j++)
		{
			k[a[j]]++;
		}
		for(long long j=l;j<=n;j++)
		{
			if(k[a[j]]!=0)
			{
				k[a[j]]=0;
				s[a[j]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
