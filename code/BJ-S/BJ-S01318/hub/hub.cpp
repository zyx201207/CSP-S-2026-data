#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t1;
int n, k, x, dis[11];
vector<int> t[11];

void help(int now){
    x ^= (1 << (now - 1));
    for (int i = 0; i < t[now].size(); i++){
        int p = t[now][i];
        if (x & (1 << (p - 1)))
            help(p);
    }
}

int check(int p){
    x = p;
    int cnt = 0;
    while (x){
        for (int i = 0; i < n; i++)
            if (x & (1 << i)){
                help(i + 1);
                break;
            }
        cnt++;
    }
    if (cnt > 2)
        return n;
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (p & (1 << i))
            dis[i + 1] = 0, q.push(i + 1);
    while (!q.empty()){
        int tq = q.front();
        q.pop();
        for (int op: t[tq])
            if (dis[op] > dis[tq] + 1)
                dis[op] = dis[tq] + 1, q.push(op);
    }
    int x = 0;
    for (int i = 1; i <= n; i++)
        x = max(x, dis[i]);
    return x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t1;
    while (t1--){
        cin >> n >> k;
        int ans = n;
        for (int i = 1; i <= n; i++)
            t[i].clear();
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v, t[u].push_back(v), t[v].push_back(u);
        for (int j = 0; j < (1 << n); j++){
            int p = 0;
            for (int i = 0; i < n; i++)
                if (j & (1 << i))
                    p++;
            if (p == k)
                ans = min(ans, check(j));
        }
        cout << ans << endl;
    }
    return 0;
}
