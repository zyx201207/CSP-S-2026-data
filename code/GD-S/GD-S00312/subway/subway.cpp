#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q,w[500005],k[500005],a[505][500005],t[505][500005],dp[1005][1005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		
	}
	return 0;
}
