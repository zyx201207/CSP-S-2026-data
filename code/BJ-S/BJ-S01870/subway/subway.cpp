#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define req(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=5e5+5;
const int M=505;
const ll INF=(1ll<<60);
ll n,m,c,d,q,w[N],k[M],x,y,G[M][M];
vector<pair<int,ll> > V[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m)cin>>w[i];
    rep(i,1,n){
        cin>>k[i];
        rep(j,1,k[i]){
            ll tmp1,tmp2;
            cin>>tmp1>>tmp2;
            V[tmp1].push_back(make_pair(i,tmp2));
        }
    }
    rep(i,1,n)rep(j,1,n)G[i][j]=INF;
    rep(i,1,n)G[i][i]=0;
    rep(i,1,m){
        int sz=V[i].size();
        if(sz<=1)continue;
        for(int j=0;j<sz-1;j++){
            for(int k=j+1;k<sz;k++){
                int u=V[i][j].first,v=V[i][k].first;
                G[u][v]=min(G[u][v],V[i][j].second+V[i][k].second);
            }
        }
    }
    rep(i,1,n)rep(j,1,n){
        ll mn=min(G[i][j],G[j][i]);
        G[i][j]=mn,G[j][i]=mn;
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n){
        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    }
    rep(_,1,q){
        cin>>x>>y;
        ll tmp=w[x]+w[y],ans=INF;
        for(auto i:V[x])for(auto j:V[y]){
            ans=min(ans,i.second+j.second+G[i.first][j.first]);
        }
        cout<<ans+tmp<<"\n";
    }
    return 0;
}