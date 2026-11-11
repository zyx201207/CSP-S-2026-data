#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool vis[300005];
int a[500005],b[300005],sum[300005],rec[300005],last[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1])
		{
			sum[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
/*
2026/10/31 10:30 Ð´ÍêÁË 
2026/10/31 10:35 Ð´´íÁË 
2026/10/31 10:35 Ð´A
*/


