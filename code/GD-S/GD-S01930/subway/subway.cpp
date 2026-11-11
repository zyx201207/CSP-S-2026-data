#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define INF 0x3f3f3f3f
#define PII pair<int,int>
#define rep(k,a,b) for (int k =a;k <= b;k ++ )
#define all(a) a.begin(),a.end()
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define vct vector 
#define endl '\n'
#define sz(a) ((int)a.size())
#define rof(k,a,b) for (int k = a;k >= b;k -- )

const int N =5e5+5;

int c, n , m , d , q;
int w[N];
ll dis[505][505];

vct<array<int,2> > v[N];
vct<array<int,2> > xian[N];

void solvemain()
{
	cin >> c >> n >> m >> d >> q;
	rep(i,1,m)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n; ++i )
	{
		int k ; cin >> k ; 
		for (int j = 1;j <= k ;j ++)
		{
			int x,t;cin >>x >> t;
			v[x].pb({i,t});
			xian[i].pb({x,t});
		}
	}
	mem(dis,0x3f);
	for (int i = 1;i <= n;i ++ )
	{
		dis[i][i] = 0 ; 
		for (auto [x,t] : xian[i])
		{
			for (auto [id,t2] : v[x])
			{
				dis[i][id] = min(dis[i][id],(ll) (t + t2));
			}
		}
	}
	for (int k = 1;k <= n;k ++ )
		for (int i = 1;i <= n;i ++)
			for (int j = 1;j <= n;j ++)
				dis[i][j] =min(dis[i][k] + dis[k][j],dis[i][j]);	


	while (q--)
	{
		int x,y;cin >> x >> y;
		ll ans = 1e18 ;
		for (auto [x1,t1] : v[x])
		{
			for (auto [x2,t2] : v[y])
			{
				ans = min(ans,t1 + t2 + dis[x1][x2]);
			}
		}
		cout << ans + w[x] + w[y] << endl;

	}

}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);

	auto st = clock();
	int t ;t =  1;
	while(t--) solvemain();


	cerr <<endl <<"Time:"<< double(clock() - st) / CLOCKS_PER_SEC<< "ms" << endl;
	return 0 ;
}