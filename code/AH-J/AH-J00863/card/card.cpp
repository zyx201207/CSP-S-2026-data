#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],n,m,b[M],sum[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<=n)
		{
			j=b[a[j]];
			sum[a[j]]++;
			j++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}
