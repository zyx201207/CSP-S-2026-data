#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	long long maxx=-1;
	for(long long i=1;i<n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			if(b[j]-b[i]-(a[j]-a[i])*(i-1)<=m)
			{
				maxx=max(maxx,j-i+1);
			}
		}
	}
	cout<<maxx;
	return 0;
} 
