#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500010];
struct edg{
    int to,x;
};
vector<edg> t[500010];
int dis[500010];
bool f[500010];
int dij(int s,int e){
    memset(dis,0x3f,sizeof dis);
    memset(f,0,sizeof f);
    dis[s]=0;
    for(int i=1;i<=m;i++){
        int u;
        for(int j=1;j<=m;j++){
            if(dis[j]<dis[i]&&f[j]==0) u=j;
        }
        f[u]=1;
        int len=t[u].size();
        for(int j=0;j<len;j++){
            int to=t[u][i].to;
            int x=t[u][i].x;
            if(dis[u]+x<dis[to]){
                dis[to]=dis[u]+x;
            }
        }
    }
    return dis[e];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int ki,ai,ti;
    for(int i=1;i<=n;i++){
        cin>>ki;
        for(int j=1;j<=ki;j++){
            cin>>ai>>ti;
            t[ai].push_back({i,ti});
        }
    }
    int x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<dij(x,y)+w[x]+w[y]<<"\n";
    }
    return 0;
}
