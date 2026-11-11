#include<bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int n,kk;
int f[100010],vis[100010],mn[100010];
int ans = 2e9;
void dfss(int k,int fa) {
    vis[k] = 1;
    for (int i=0;i<v[k].size();i++) {
        int x = v[k][i];
        if (x != fa && f[x] == 1) {
            dfss(x,k);
        }
    }
}
void dfsss(int k,int fa,int s) {
    mn[k] = min(mn[k],s);
    for (int i=0;i<v[k].size();i++) {
        int x = v[k][i];
        if (x != fa) {
            dfsss(x,k,s+1);
        } 
    }
}
void dfs(int k,int s) {
    if (k == n+1) {
        if (s != kk) {
            return ;
        }
        for (int i=1;i<=n;i++) {
            vis[i] = 0;
            mn[i] = 2e9;
        }
        int cnt = 0;
        for (int i=1;i<=n;i++) {
            if (f[i] == 1 && vis[i] == 0) {
                cnt++;
                dfss(i,-1);
            }
            if (cnt > 2) {
                return ;
            }
        }
        for (int i=1;i<=n;i++) {
            if (f[i] == 1) {
                dfsss(i,-1,0);
            }
        }
        int mx = 0;
        for (int i=1;i<=n;i++) {
            mx = max(mx,mn[i]);
        }
        ans = min(ans,mx);
        return ;
    }
    if (n-k+1 < kk-s) {
        return ;
    }
    f[k] = 0;
    dfs(k+1,s);
    if (s+1 <= kk) {
        f[k] = 1;
        dfs(k+1,s+1);
    }
    f[k] = 0;
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for (int o=1;o<=t;o++) {
        scanf("%d%d",&n,&kk);
        for (int i=1;i<=n;i++) {
            v[i].clear();
        }
        for (int i=1;i<n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans = 2e9;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}