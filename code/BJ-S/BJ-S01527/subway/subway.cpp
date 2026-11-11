#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+10,M=5e5+10;
int c,n,m,q,d;
ll w[M];
ll dist[N][N];
vector<pair<int,ll>> in[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin >>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >>k;
        for(int x=1;x<=k;x++){
            int ver,tim;
            cin >>ver>>tim;
            in[ver].push_back({i,tim});
        }
    }
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto [v1,tim1]:in[i]){
            for(auto [v2,tim2]:in[i]){
                if(v1!=v2){
                    dist[v1][v2]=dist[v2][v1]=min({dist[v1][v2],dist[v2][v1],tim1+tim2});
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin >>x>>y;
        ll ans=9e18;
        for(auto [v1,tim1]:in[x]){
            for(auto [v2,tim2]:in[y]){
                ans=min(ans,dist[v1][v2]+w[x]+w[y]+tim1+tim2);
            }
        }
        cout <<ans<<"\n";
    }
    return 0;
}
