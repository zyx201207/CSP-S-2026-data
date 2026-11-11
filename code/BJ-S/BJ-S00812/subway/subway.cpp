#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005];
int K[505];
vector<int> a[505],t[505];
vector<pair<int,int> > aa[500005];
vector<pair<int,long long> > edges[505];
long long f[505][505];
long long ff[505][505];
set<pair<long long,int> > dij;
void DJ(int S){
    for(int i=1;i<=n;i++){
        f[S][i]=1e18;
    }
    f[S][S]=0;
    for(int i=1;i<=n;i++){
        dij.insert({f[S][i],i});
    }
    while(!dij.empty()){
        int x=dij.begin()->second;
        dij.erase(dij.begin());
        if(f[S][x]==1e18)continue;

        for(auto y:edges[x]){
            if(f[S][x]+y.second<f[S][y.first]){
                dij.erase({f[S][y.first],y.first});
                f[S][y.first]=f[S][x]+y.second;
                dij.insert({f[S][y.first],y.first});
            }
        }
    }
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d ",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d ",&K[i]);
        for(int j=1;j<=K[i];j++){
            int x,y;
            scanf("%d %d ",&x,&y);
            a[i].push_back(x);
            t[i].push_back(y);
            aa[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ff[i][j]=1e18;
        }
    }
    for(int x=1;x<=n;x++){
        for(int i=1;i<=K[x];i++){
            for(auto y:aa[a[x][i-1]]){
                if(y.first==x) continue;
                if(t[x][i-1]+y.second<ff[x][y.first]){
                    ff[x][y.first]=t[x][i-1]+y.second;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ff[i][j]!=1e18){
                edges[i].push_back({j,ff[i][j]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        DJ(i);
    }
    while(q--){
        int X,Y;
        scanf("%d %d",&X,&Y);
        long long ans=1e18;
        for(auto xx:aa[X]){
            for(auto yy:aa[Y]){
                ans=min(ans,f[xx.first][yy.first]+xx.second+yy.second);
            }
        }
        cout<<ans+w[X]+w[Y]<<"\n";
    }
    return 0;
}
