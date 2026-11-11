#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,p[105][105],dis[105][105],ch[105],cnt,ans=0x3f3f3f3f;
bool vis[105],vv[105];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(!vv[u])
            continue;
        if(vis[u])
            continue;
        vis[u]=1;
        for(int v=1;v<=n;v++) {
            if(p[u][v])
                q.push(v);
        }
    }
}
void dfs(int u) {
    if(cnt>k)
        return ;
    if(cnt+n-u+1<k)
        return ;
    if(u>n) {
        if(cnt==k) {
            for(int i=1;i<=n;i++)
                vis[i]=0;
            int cc=0;
            for(int i=1;i<=cnt;i++) {
                if(!vis[ch[i]]) {
                    bfs(ch[i]);
                    cc++;
                }
            }
            if(cc>2)
                return ;
            int sm=0;
            for(int i=1;i<=n;i++) {
                int mn=0x3f3f3f3f;
                for(int j=1;j<=cnt;j++)
                    mn=min(mn,dis[i][ch[j]]);
                sm=max(sm,mn);
            }
            ans=min(ans,sm);
        }
        return ;
    }
    dfs(n+1);
    for(int i=u;i<n;i++) {
        vv[i]=1;
        ch[++cnt]=i;
        dfs(i+1);
        cnt--;
        vv[i]=0;
    }
}
void solve() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dis[i][j]=0x3f3f3f3f;
            p[i][j]=0;
        }
        dis[i][i]=0;
    }
    ans=0x3f3f3f3f;
    cnt=0;
    for(int i=1;i<n;i++) {
        scanf("%d%d",&u,&v);
        p[u][v]=p[v][u]=dis[u][v]=dis[v][u]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    dfs(1);
    printf("%d\n",ans);
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++)
        solve();
    return 0;
}