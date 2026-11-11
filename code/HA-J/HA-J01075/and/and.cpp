#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m;
int v[N];
int sum[N];
int maxsum;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	sort(v+1,v+n+1);
	sum[0]=v[1];
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]&v[i];
	}
	for(int i=m;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			maxsum=max(maxsum,sum[i]&sum[j-1]);
		}
	}
	cout<<v[n];
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T;
	T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
