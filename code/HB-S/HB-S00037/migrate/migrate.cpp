#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],dis[2000005],pth[2000005],ans;
void bfs(int s) {
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++) {
        pth[i]=0;
        dis[i]=0x3f3f3f3f;
    }
    q.push({s,0});
    while(!q.empty()) {
        int u=q.front().first,w=q.front().second;
        q.pop();
        if(pth[u]) {
            if(w==dis[u])
                pth[u]++;
            continue;
        }
        pth[u]++;
        dis[u]=w;
        for(int v=u+1;v<=n;v++) {
            if(a[v]-a[u]>d)
                continue;
            q.push({v,w+1});
        }
    }
}
void solve() {
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(c>=11 && c<=12) {
        if(d/(a[2]-a[1])>1)
            printf("%d\n",max(n-2*d/(a[2]-a[1])+1,0));
        else
            printf("0\n");
    }
    else {
        ans=0;
        for(int i=1;i<=n;i++) {
            bfs(i);
            for(int j=i+1;j<=n;j++)
                if(pth[j]==2)
                    ans++;
        }
        printf("%d\n",ans);
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++)
        solve();
    return 0;
}