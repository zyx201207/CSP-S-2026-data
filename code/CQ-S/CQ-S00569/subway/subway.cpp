#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 500 + 5;
const ll M = 5e5 + 5;
const ll INF = 1e18;

struct Node{
	ll li;
	ll ti;
};
vector <Node> store[M];
ll casess,n,m,d,q;
ll station_cost[M];
ll f[N][N];
void chmin(ll& x,ll y)
{
	x = min(x,y);
	return;
}
int main(void)
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	clock_t st = clock();
	memset(f,0x3f,sizeof f);
	cin >> casess >> n >> m >> d >> q;
	for(ll i = 1;i <= n;i++)
		f[i][i] = 0;
	for(ll i = 1;i <= m;i++)
		cin >> station_cost[i];
	for(ll i = 1;i <= n;i++)
	{
		ll k;
		cin >> k;
		for(ll j = 0;j < k;j++)
		{
			ll a,t;
			cin >> a >> t;
			store[a].push_back({i,t});
		}
	}
//	fprintf(stderr,"%.2lf\n",(clock() - st) / (double)CLOCKS_PER_SEC);
	for(ll i = 1;i <= m;i++)
	{
		for(ll j = 0;j < (ll)store[i].size();j++)
			for(ll k = 0;k < (ll)store[i].size();k++)
				chmin(f[store[i][j].li][store[i][k].li],store[i][j].ti + store[i][k].ti);
	}
	for(ll k = 1;k <= n;k++)
		for(ll i = 1;i <= n;i++)
			for(ll j = 1;j <= n;j++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	while(q--)
	{
		ll x,y;
		cin >> x >> y;
		ll ans = INF;
		for(ll i = 0;i < (ll)store[x].size();i++)
			for(ll j = 0;j < (ll)store[y].size();j++)
				ans = min(ans,store[x][i].ti + store[y][j].ti + f[store[x][i].li][store[y][j].li]);
		cout << ans + station_cost[x] + station_cost[y] << '\n';
	}
	return 0;
}
