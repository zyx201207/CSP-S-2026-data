#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
long long n, m, a[N], pre[M], sum[M];
vector<long long> g[M];
void dfs(long long u, long long fa){
    for (int v : g[u]){
        if (v == fa)
            continue;
        dfs(v, u);
        sum[u] += sum[v];
    }
    return ;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        pre[a[i]] = i, sum[a[i]] ++;
    for (int i = 1; i <= m; i ++)
        g[a[pre[i] + 1]].push_back(i);
    dfs(a[n], 0);
    for (int i = 1; i <= m; i ++)
        cout << sum[i] << " ";
    return 0;
}
