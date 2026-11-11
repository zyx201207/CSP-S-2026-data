#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
int cid,n,k, s1, s2, o1,o2, rt, trd;
vector<int> g[N];
int deg[N], dep[N], md[N];
int stt, stk[N];
int ans;

void solveA(){
    int d = (n+1) / 2, k1 = k / 2, k2 = (k+1) / 2;
    if (k == 1){
        cout << (d + 1) / 2 << '\n';
    }
    else{
        cout << (d + 2 - k  +  2) / 3 << '\n';
    }
}

int mxd = 0, mxson = 0;
void dfs1(int u, int fath, int d){
    if (d > mxd){
        d = mxd;
        mxson = u;
    }
    for (int v : g[u]){
        if (v == fath) continue;
        dfs1(v,u,d+1);
    }
}

bool dfs2(int u, int fath){
    bool is = false;
    for (int v : g[u]){
        if (v == fath) continue;
        if (dfs2(v, u)){
            stk[++stt] = u;
            is = true;
        }
    }
    if (u == s2) stk[++stt] = u;
    return is || u == s2;
}

void dfs3(int u, int fath){
    dep[u] = dep[fath] + 1;
    md[u] = dep[u];
    for (int v : g[u]){
        if (v == fath) continue;
        dfs3(v,u);
        md[u] = max(md[u], md[v]);
    }
}

bool choice[15], vis[N];
int mxdis[15];
void dfs5(int u, int fath){
    for (int v : g[u]){
        if (mxdis[v] > mxdis[u] + 1){
            mxdis[v] = mxdis[u] + 1;
            dfs5(v,u);
        }
    }
}
void dfs6(int u){
    vis[u] = true;
    for (int v : g[u]){
        if (!vis[v] && choice[v]) dfs6(v);
    }
}
void dfs4(int cur, int now){
    if (cur == n+1){
        memset(mxdis, 0x3f, sizeof(mxdis));
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (!vis[i] && choice[i]){
                dfs6(i);
                cnt++;
                if (cnt > 2) return;
            }
        }
        for (int i = 1; i <= n; i++){
            if (choice[i]){
                mxdis[i] = 0;
                dfs5(i,0);
            }
        }
        int mxdd = 0;
        for (int i = 1; i <= n; i++){
            mxdd = max(mxdd, mxdis[i]);
        }
        ans = min(ans, mxdd);
        return;
    }
    if (n - cur >= k - now){
        dfs4(cur + 1, now);
    }
    if (now < k){
        choice[cur] = true;
        dfs4(cur + 1, now + 1);
        choice[cur] = false;
    }
        
}

void solveB(){
    dfs4(1, 0);
    cout << ans << '\n';
}

void solve(){
    cin >> n >> k;
    for (int i = 0; i <= n; i++) g[i].clear();
    memset(deg, 0, sizeof(int) * (n+2));
    for (int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    ans = 1e9;
    if (k >= n){
        cout << 0; return;
    }
    if (13 <= cid && cid <= 14){
        solveA(); return;
    }
    if (n <= 10){
        solveB(); return;
    }
    s1 = s2 = mxd = mxson = 0;
    dfs1(1, 0, 0);
    s1 = mxson;
    mxd = mxson = 0;
    dfs1(s1, 0, 0);
    s2 = mxson;
    stt = 0;
    dfs2(s1,0);
    rt = stk[(stt+1)/2];
    trd = stt;
    dfs3(rt, 0);
    ans = md[rt];
    o1 = o2 = rt;
    int lsto1 = rt, lsto2 = rt;
    bool need1 = true, need2 = true;
    for (int loop = 1; loop <= ans*2 + 1; ){
        if (need1 && loop <= ans*2 + 1){
            int cho1 = 0, cho2 = 0;
            for (int v : g[o1]){
                if (v == lsto1) continue;
                if (md[cho1] < md[v]) cho1 = v;
                else if (md[cho2] < md[v]) cho2 = v;
            }
            if (!cho1 && !cho2 && md[cho1] - md[cho2] <= 1){
                need1 = false;
                break;
            }
            o1 = cho1;
            //ans = min(ans, md[o2] +  )
            loop++;
        }
        if (loop <= ans*2 + 1){

            loop++;
        }
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> cid >> t;
    while (t--) solve();
    return 0;
}