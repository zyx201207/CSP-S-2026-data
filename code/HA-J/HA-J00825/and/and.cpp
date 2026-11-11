#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		a.push_back(x);
	}
	int maxx=-1;
	for(long long i=0;i<=n-m;i++)
	{
		for(long long j=i;j<=n-m;j++)
		{
			int ans=a[i];
			for(long long k=j+1;k<j+m;k++)
			{
				ans=ans&a[k];
			}
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
}
