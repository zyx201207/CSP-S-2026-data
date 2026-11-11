#include<bits/stdc++.h>
#define int long long
using namespace std;

int CASE,T;
int n,dd;
int a[2000010],f[2000010],rf[2000010],sum[2000010],cnt[2000010],g[2000010];
int nxt[2000010],pst[2000010],fsum[2000010];

int d[310][310],ans[310][310];

int solve(int u){
    for(int v=u+1;v<=n;v++){
        if(d[u][v]==1) continue;
        if(d[u][v]==n+1)break;
        for(int i=u+1;i<v;i++){
            if(d[u][i]+d[v][i]==d[u][v]){
                ans[u][v]+=(ans[u][i]*ans[i][v]);
            }
        }
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>CASE>>T;
    while(T--){
        cin>>n>>dd;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) d[i][j]=n+1;
            for(int j=1;j<=n;j++) ans[i][j]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>dd) break;
                d[i][j]=1;
                ans[i][j]=1;
            }
        }
        for(int l=2;l<n;l++){
            for(int p=1;p<=n-l;p++){
                int q=p+l;
                if(d[p][q]==1) continue;
                d[p][q]=n+1;
                for(int r=p+1;r<q;r++){
                    if((a[r]-a[p]<=dd)&&(a[q]-a[r]<=dd))
                        d[p][q]=min(d[p][q],d[p][r]+d[r][q]);
                }
            }
        }
        for(int i=n;i>=1;i--) solve(i);
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(ans[i][j]==2){
                    res++;
                }
            }
        }
        cout<<res<<'\n';
    }

    return 0;
}
