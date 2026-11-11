# include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
vector <int> g[N];
int a[N], b[N], d[N], n, k, ans;

void dfs(int u,int fa){
    b[u] = 1;
    for (int v : g[u]){
        if (a[v] == 0 || v == fa) continue ;
        dfs(v, u);
    }
}

bool check(){
    int cnt = 0;
    for (int i=1;i<=k;i++){
        if (b[d[i]] == 0){
            dfs(d[i], d[i]);
            cnt++;
        }
    }
    if (cnt > 2) return false;
    return true;
}

void ddfs(int u,int fa){
    b[u] = b[fa] + 1;
    for (int v : g[u]){
        if (v == fa || a[v] == 1 || b[v] < b[fa] + 1){
            continue ;
        }
        ddfs(v, u);
    }
}

void dfs(int step){
    if (step > k){
        for (int i=1;i<=n;i++) b[i] = 0;
        if (check() == 0) return ;
        for (int i=1;i<=n;i++) b[i] = 0x3f3f3f3f;
        for (int i=1;i<=k;i++){
            b[d[i]] = -1;
            ddfs(d[i], d[i]);
        }
        int mx = 0;
        for (int i=1;i<=n;i++){
            mx = max(mx, b[i]);
        }
        if (mx == 1){
//            for (int i=1;i<=k;i++){
//                cout << d[i] << " ";
//            }
//            cout << endl;
//            for (int i=1;i<=n;i++){
//                cout << b[i] << " ";
//            }
//            cout << endl;
        }
        ans = min(ans, mx);

        return ;
    }
    for (int i=1;i<=n;i++){
        if (a[i] == 0){
            a[i] = 1;
            d[step] = i;
            dfs(step+1);
            a[i] = 0;
        }
    }
}

void Main(){
    for (int i=1;i<=n;i++){
        g[i].clear();
        a[i] = b[i] = d[i] = 0;
    }
    cin >> n >> k;
    for (int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans = 1e9+7;
    dfs(1);
    cout << ans <<endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--){
        Main();
    }
    return 0;
}
