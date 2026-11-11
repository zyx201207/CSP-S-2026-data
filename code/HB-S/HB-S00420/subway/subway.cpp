#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y, ans;
struct node{
    int u, nxt, to;
}p[100000005];
int a[500005], cnt, head[500505];
void add(int from, int t, int l){
    p[++cnt].nxt = head[from];
    p[cnt].to = t;
    p[cnt].u = l;
    head[from] = cnt;
}
bool vis[500505];
void dfs(int s, int v){
    if(s == y){
        ans = min(ans, v);
    }
    for(int i = head[s]; i; i = p[i].nxt){
        if(!vis[p[i].to]){
            vis[p[i].to] = 1;
            dfs(p[i].to, v + p[i].u);
            vis[p[i].to] = 0;
        }
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        int j;
        cin >> j;
        for(int l = 1; l <= j; l++){
            cin >> x >> y;
            add(m + i, x, y);
            add(x, m + i, y);
        }
    }
    for(int i = 1; i <= q; i++){
        ans = 5e8;
        memset(vis, 0, sizeof(vis));
        cin >> x >> y;
        dfs(x, 0);
        cout << ans + a[x] + a[y]<< "\n";
    }
    return 0;
}
