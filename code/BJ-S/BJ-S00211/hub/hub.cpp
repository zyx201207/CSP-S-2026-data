#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int c , T;
int n , m , d[105][105] , st[105] , ans = 100000 , res;
vector<int> g[N];

int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> c >> T;
	if(c <= 3)
	{
		while(T --)
		{
			ans = 100000;
			cin >> n >> m;
			memset(d , 0x3f, sizeof d);
			for(int i = 1 ; i <= n;  ++ i) g[i].clear();
			for(int i = 1 ; i < n;  ++ i)
			{
				int u , v;
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
				d[u][v] = d[v][u] = 1;
			}
			for(int i = 1 ; i <= n ; ++ i) d[i][i] = 0;
			
			for(int i = 1 ; i <= n ; ++ i)
				for(int j = 1 ; j <= n ; ++ j)
					for(int k = 1 ; k <= n ; ++ k)
						d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
			
			res = 1000;
			for(int i = 0 ; i < (1 << n) ; ++ i)
			{
				memset(st , 0 , sizeof st);
				int cnt = 0 , res = 0;
				for(int j = 0 ; j < n ; ++ j) if(i & (1 << j))
					++ cnt;
				if(cnt > m) continue;
				for(int j = 0 ; j < n ; ++ j)
					if(i & (1 << j))
						st[j + 1] = 1;
				
				int num = 0;
				for(int i = 1 ; i <= n ; ++ i)
					for(int j = 1 ; j <= n ; ++ j)
						if(st[i] && st[j] && d[i][j] > 1)
							++ num;
				if(num > 2) continue;
				
				for(int i = 1 ; i <= n ; ++ i)
				{
					int dist = 100000;
					for(int j = 1 ; j <= n ; ++ j)
						if(st[j])
							dist = min(dist , d[i][j]);
					res = max(res , dist);
				}
				
				ans = min(ans , res);
			}
			cout << ans << '\n';
		}
	}
	else
	{
		while(T --)
		{
			cin >> n >> m;
			for(int i = 1 ; i < n ; ++ i)
			{
				int u , v;
				cin >> u >> v;
			}
			if(m == n) cout << "0\n";
			else cout << "1\n";
		}
	}
	
	return 0;
}
