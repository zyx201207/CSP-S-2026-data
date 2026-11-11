#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+5;
int c,n,m,d,q,a[M],dis[N][N],ans;
struct nd{int v,w;};
vector<nd> st[M],li[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)cin >> a[i];
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int v,w;
            cin >> v >> w;
            st[v].push_back({i,w});
            li[i].push_back({v,w});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int u=1;u<=n;u++){
        dis[u][u]=0;
        for(auto now:li[u]){
            int t=now.v,w1=now.w;
            for(auto now2:st[t]){
                int v=now2.v,w2=now2.w;
                dis[u][v]=min(dis[u][v],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        ans=1e18;
        for(auto now:st[x]){
            int u=now.v,w1=now.w;
            for(auto now2:st[y]){
                int v=now2.v,w2=now2.w;
                ans=min(ans,dis[u][v]+w1+w2);
            }
        }
        cout << ans+a[x]+a[y] << endl;
    }
    return 0;
}
