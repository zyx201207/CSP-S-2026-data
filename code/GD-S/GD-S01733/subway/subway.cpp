#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int c , n , m , d , q , w[N] , fl[N][N];
vector<pair<int , int> > vc[N];
bool vis[N][N];

int calc(int u , int k , int v)
{
	int uk = 0 , kv = 0;
	bool flaguk = 0 , flagkv = 0 , flaguv = 0;
	for(int i = 1; i<=n; i++)
	{
		if(vis[i][u] && vis[i][k])
		{
			flaguk = 1;
		}
		if(vis[i][k] && vis[i][v])
		{
			flagkv = 1;
		}
		if(vis[i][u] && vis[i][v])
	}
	if(!flaguk)
		uk = 0;
	if(!flagkv)
		kv = 0;
}

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i<=m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i<=n; i++)
	{
		int u;
		cin >> u;
		for(int j = 1; j<=u; j++)
		{
			int a , t;
			cin >> a >> t;
			vc[i].push_back({a , t});
			vis[i][a] = 1;
		}	
	}
	
	for(int k = 1; k<=m; k++)
	{
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				fl[i][j] = min(fl[i][j] , calc(i , k , j));
			}
		}
	}
	
	for(int i = 1; i<=q; i++)
	{
		int u , v;
		cin >> u >> v;
		cout <<	fl[u][v];
	}
	
	return 0;
}
