#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5005;

int n, d, a[MAXN];
int dis[MAXN], sum[MAXN], f[MAXN], g[MAXN], R[MAXN];

int ans;
void dfs(int x, int u, int dis){
	if(x == u){
		f[dis]++;
		return ;
	}
	for(int i = x + 1; i <= u; ++i){
		if(a[i] - a[x] <= d) dfs(i, u, dis + 1);
	} 
}

void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
    	for(int j = i + 1; j <= n; ++j){
    		for(int k = 0; k <= n; ++k) f[k] = 0;
    		ans = 0;
    		dfs(i, j, 0);
    		for(int k = 0; k <= n; ++k) if(f[k]){
    			if(f[k] == 2) cnt++;
    			break;
			} 
		}
	}
	cout << cnt << '\n';
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--)
        solve();

    return 0;
}
