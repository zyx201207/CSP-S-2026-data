#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,n,a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	for(long long i=2;i<=m;i++)
	{
		for(long long k=i-1;k>=1;k--)
		{
			sum[i]+=a[i]-a[k];
		}
	}
	sum[1]=0;
	for(long long i=1;i<=m;i++)
	{
		if(sum[i]<=n&&sum[i+1]>n)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<m;
	return 0;
}
