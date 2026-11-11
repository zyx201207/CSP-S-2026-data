#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q;
const int N=5e5+10;
const int M=510;
const int INF=1e18+10;
int a[M][M];
int w[N];
int dis[M][M];
struct node{
    int v,w;
};
vector<node>ve[N];
void dj(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
            }
        }
    }
}
void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j]<<" ";
        }
        cout <<endl;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) a[i][j]=INF;
    }
    for(int i=1;i<=n;i++) a[i][i]=0;
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int vv,ww;
            cin >> vv >> ww;
            int len=ve[vv].size();
            //cout <<len<<endl;
            for(int k=0;k<len;k++){
                int v=ve[vv][k].v,w=ve[vv][k].w;
                //cout << i <<' '<< v<<endl;
                a[i][v]=a[v][i]=min(a[i][v],w+ww);
            }
            ve[vv].push_back({i,ww});
        }
    }
    //pr();
    dj();
    while(q--){
        int s,e;
        cin >> s >> e;
        int ans=INF;
        for(int i=0;i<ve[s].size();i++){
            int ids=ve[s][i].v,ws=ve[s][i].w;
            for(int j=0;j<ve[e].size();j++){
                int ide=ve[e][j].v,we=ve[e][j].w;
                ans=min(ans,a[ids][ide]+ws+we+w[s]+w[e]);
            }
        }
        cout << ans<<endl;
    }
    return 0;
}
