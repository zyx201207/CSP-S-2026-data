#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 15, M = 500100;
ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void write(ll x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x <= 9){
        putchar(x + '0');
        return;
    }
    write(x / 10);
    putchar(x % 10 + '0');
}

int n, k, dist[N][N];
vector<int> edges[N];

void dfs(int s, int u, int fa){
    for (auto v : edges[u]){
        if(v == fa)
            continue;
        dist[s][v] = dist[s][u] + 1;
        dfs(s, v, u);
    }
}

int t, c[N], ans = INT_MAX, b[N];

void DFS(int u, int fa){
	for (auto v : edges[u]){
		if(v == fa || c[v] == 0)
			continue;
		b[v] = 1;
		DFS(v, u);
	}
}

void solve(int p){
    if(p > n){
        if(t < k)
            return;
        int mx = 0, s = 0;
        for (int i = 1; i <= n; i++)
        	b[i] = 0;
        for (int i = 1; i <= n; i++){
        	if(c[i] && !b[i]){
        		s++;
        		if(s > 2)
        			return;
        		DFS(i, 0);
			}
		}
        for (int i = 1; i <= n; i++){
            int mn = INT_MAX;
            for (int j = 1; j <= n; j++){
            	if(c[j])
            	    mn = min(mn, dist[i][j]);
            }
            mx = max(mx, mn);
        }
        ans = min(mx, ans);
        return;
    }
    solve(p + 1);
    if(t < k){
        t++;
        c[p] = 1;
        solve(p + 1);
        t--;
        c[p] = 0;
    }
}

void solve(){
    n = read(), k = read();
    for (int i = 1; i <= n; i++){
    	edges[i].clear();
	}
    for (int i = 1; i < n; i++){
        int u = read(), v = read();
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ans = INT_MAX;
    t = 0;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++){
        dist[i][i] = 0;
        dfs(i, i, 0);
    }
    solve(1);
    write(ans);
    puts("");
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
    int c = read();
    int T = read();
    while(T--){
        solve();
    }
}
