#include<bits/stdc++.h>
#define N 50001
#define int long long
using namespace std;
int c,n,m,d,q;
int k[N];
int w[N];
int a[501][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int cnt;
			cin>>cnt;
			cin>>a[cnt][i];
		}
	}
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		int ans=w[s]+w[e];
		for(int i=s;i<=e;i++)
		{
			ans+=a[i][s]+a[i][e];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
