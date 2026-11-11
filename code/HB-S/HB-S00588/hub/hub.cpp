#include <bits/stdc++.h>
using namespace std;
//g++ hub.cpp -o hub -std=c++14 -Wall -O2

typedef long long ll;
const int N = 5e5 + 5;
int subtask, n, k, T;
int head[N], vis[N], d[N], f[N][20], F[N];

struct edge{
    int to, nxt;
}e[N*2];

int cnt = 0, tot = 0;

void add(int u, int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa){
    d[u] = d[fa] + 1;
    f[u][0] = fa;
    for(int i=1; (1<<i)<d[u]; i++){
        f[u][i] = f[f[u][i-1]][i-1];
    }
    for(int i=head[u]; i; i=e[i].nxt){
        int v = e[i].to;
        if(v != fa) dfs(v, u);
    }
}

int lca(int x, int y){
    if(d[x] > d[y]) swap(x, y);
    for(int i=19; i>=0; i--){
        if(d[x]+(1<<i) <= d[y]){
            y = f[y][i];
        }
    }
    if(x == y) return x;
    for(int i=19; i>=0; i--){
        if(f[x][i] == f[y][i]) continue;
        else
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}

bool check(int u, int fa){
    bool res = 1;
    if(tot > 2){
        return false;
    }
    if(vis[u]){
        if(!vis[fa]) F[u] = ++tot;
        else F[u] = fa;
    }
    for(int i=head[u]; i; i=e[i].nxt){
        int v = e[i].to;
        if(v != fa) res = check(v, u);
        if(!res) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("hub3.in", "r", stdin);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin>>subtask>>T;
    while(T--){
        cin>>n>>k;
        fill(head+1, head+1+n, 0);
        cnt = 0;
        for(int i=1; i<n; i++){
            int u, v;
            cin>>u>>v;
            add(u, v);
            add(v, u);
        }
        dfs(1, 0);
        int ant = INT_MAX;
        for(int st=0; st<(1<<n); st++){
            int c = 0;
            vector <int> vi;
            for(int i=0; i<n; i++){
                vis[i+1] = 0;
                if((st>>i) & 1) c++;
            }
            if(c != k) continue;
            // cout<<"vis: ";
            for(int i=0; i<n; i++){
                if((st>>i) & 1){
                    vis[i+1] = 1;
                    // cout<<i+1<<' ';
                    vi.push_back(i+1);
                }
                F[i+1] = i+1;
            }
            // cout<<'\n';
            tot = 0;
            int ans = 0;
            bool flag = check(1, 0);
            // bool flag = 1;
            // cout<<"flag = "<<flag<<'\n';
            if(flag){
                for(int i=1; i<=n; i++){
                    int res = INT_MAX;
                    for(int j=0; j<vi.size(); j++){
                        int v = vi[j];
                        // int len = 0;
                        int p = lca(i, v);
                        // cout<<"i = "<<i<<", v = "<<v<<", p = "<<p<<'\n';
                        int len = d[i] + d[v] - 2*d[p];
                        // cout<<"len = "<<len<<'\n';
                        res = min(res, len);
                    }
                    ans = max(ans, res);
                }
                ant = min(ant, ans);
                // cout<<"----------------\n";
            }
        }
        cout<<ant<<'\n';
        
    }
    return 0;
}

/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/