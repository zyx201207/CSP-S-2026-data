#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const int N=1e6+100,M=500+10;
int c,n,m,d,q;
long long w[N];
int k[N];
vector<pair<int,long long> > a[N];
long long  e[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            e[i][j]=INF;
        }
        e[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,t;
            cin>>x>>t;
            a[x].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=m;i++){
        for(pair<int,long long> x : a[i]){
            for(pair<int,long long> y : a[i]){
                if(x==y) continue;
                e[x.first][y.first]=min(e[x.first][y.first],x.second+y.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        if(u==v){
            cout<<0<<endl;
            continue;
        }
        cin>>u>>v;
        long long ans=INF;
        for(pair<int,long long> x : a[u]){
            for(pair<int,long long> y : a[v]){
                ans=min(ans,e[x.first][y.first]+x.second+y.second);
            }

        }
        ans+=w[u]+w[v];
        cout<<ans<<endl;


    }
    return 0;
}
