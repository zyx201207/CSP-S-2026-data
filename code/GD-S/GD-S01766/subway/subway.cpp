#include<bits/stdc++.h>
using ll=long long;
using namespace std;
constexpr int N=505;
constexpr int M=5e5+5;
int c, n, m, d, q;
ll w[M], f[N][N];
vector<array<ll, 2>> e[M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)  cin>>w[i];
	for(int i=1; i<=n; i++)
	{
		int k;
		cin>>k;
		for(int j=1; j<=k; j++)
		{
			int a, t;
			cin>>a>>t;
			e[a].push_back({i, t});
		}
	}
	memset(f, 0x3f, sizeof f);
	for(int i=1; i<=n; i++) f[i][i]=0;
	for(int i=1; i<=m; i++)
	{
		for(int j=0; j<e[i].size(); j++)
		{
			auto [a, t]=e[i][j];
			for(int k=j+1; k<e[i].size(); k++)
			{
				auto [_a, _t]=e[i][k];
				f[a][_a]=min(f[a][_a], t+_t);
				f[_a][a]=min(f[_a][a], t+_t);
			}
		}
	}
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i==j || i==k || j==k) continue;
				f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto [a, t] : e[x])
		{
			for(auto [_a, _t] : e[y])
			{
				ans=min(ans, f[a][_a]+t+_t);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}