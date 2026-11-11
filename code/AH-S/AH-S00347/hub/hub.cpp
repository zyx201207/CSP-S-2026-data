#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
int c,T,n,k,vis[20],f[20][20];
PII a[20];
vector<int> g[20];
void dfs(int x,int i,int fa){
    for(auto v:g[x]){
            if(v==fa) continue;
        f[i][v]=f[i][x]+1;
        dfs(v,i,x);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            cin>>a[i].fir>>a[i].sec;
            g[a[i].fir].push_back(a[i].sec);
            g[a[i].sec].push_back(a[i].fir);
        }
        for(int i=1;i<=n;i++){
            f[i][i]=0;
            dfs(i,i,i);
        }
        int ans=1e18;
        for(int i=0;i<(1<<n);i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if((i>>j)&1) vis[j+1]=1,cnt++;
                else vis[j+1]=0;
            }
            if(cnt!=k) continue;
            for(int j=1;j<=n-1;j++){
                if(vis[a[j].fir]&&vis[a[j].sec]) cnt--;
            }
            if(cnt<=2){
                int mx=0;
                for(int j=1;j<=n;j++){
                        int minn=1e18;
                    for(int k=1;k<=n;k++){
                        if(vis[k]) minn=min(minn,f[j][k]);
                    }
                    mx=max(mx,minn);
                }
                ans=min(ans,mx);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
