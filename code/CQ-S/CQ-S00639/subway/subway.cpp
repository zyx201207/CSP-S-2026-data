#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
const ll inf=1e18;
int C,n,m,d,q,len[N];ll w[M],dis[N][N];
vector<pair<int,ll> > v[M],line[N];
int main(){
    // double ST=clock();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>len[i];
        for(int j=1;j<=len[i];j++){
            int a;ll t;cin>>a>>t;
            line[i].push_back({a,t});
            v[a].push_back({i,t});
        }
    }
    // memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            dis[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<len[i];j++){
            int u=line[i][j].first;ll w=line[i][j].second;
            for(auto k:v[u]){
                dis[i][k.first]=min(dis[i][k.first],w+k.second);
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
        int s,t;cin>>s>>t;
        ll res=inf;
        for(auto i:v[s]){
            for(auto j:v[t]){
                res=min(res,dis[i.first][j.first]+i.second+j.second);
            }
        }
        res+=w[s]+w[t];
        cout<<res<<"\n";
    }
    // cerr<<1000.0*(clock()-ST)/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}