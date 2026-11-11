#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,T,n,vis[15];
ll d,x[N];
void dfs(int now,int en,int cnt) {
    if(now==en) {
        vis[cnt]++;
        return;
    }
    for(int i=now+1;i<=en;i++) {
        if(x[i]-x[now]<=d) {
            dfs(i,en,cnt+1);
        }
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--) {
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++) {
            cin>>x[i];
        }
        ll ans=0;
        if(c<=2) {
            for(int l=1;l<n;l++) {
                for(int r=l+1;r<=n;r++) {
                    memset(vis,0,sizeof(vis));
                    dfs(l,r,0);
                    for(int i=1;i<=n;i++) {
                        if(vis[i]) {
                            if(vis[i]==2) ans++;
                            else break;
                        }
                    }
                }
            }
        }
        else {
            ans=0;
            for(int l=1;l<n;l++) {
                int L=l,tmp=0;
                for(int r=l+1;r<=n;r++) {
                    if(x[r]-x[L]>=d) tmp++,L=r;
                    if(tmp==2) ans++;
                }
                if(x[n]-x[L]>d||L!=n) {
                   tmp++;
                    if(tmp==2) ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
