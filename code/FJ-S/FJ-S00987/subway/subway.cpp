#include<bits/stdc++.h>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
#define ll long long
using namespace std;
bool mbg;

const int N=505,M=500005;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int c,n,m,d,q;
int w[M];
vector<pair<int,int>>at[M];
ll dist[N][N];

il void minto(ll &x,ll y){
    x=min(x,y);
}

bool med;
signed main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    cerr<<(&mbg-&med)/1024.0/1024<<"MB\n";
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    forto(i,1,m)cin>>w[i];
    forto(i,1,n){
        int k,a,t;cin>>k;
        while(k--){
            cin>>a>>t;
            at[a].emplace_back(i,t);
        }
    }
    memset(dist,INF,sizeof(dist));
    forto(i,1,n)dist[i][i]=0;
    forto(i,1,m){
        int sz=at[i].size();
        for(int j=0;j<sz;j++)for(int k=j+1;k<sz;k++){
            minto(dist[at[i][j].first][at[i][k].first],at[i][j].second+at[i][k].second);
            minto(dist[at[i][k].first][at[i][j].first],at[i][j].second+at[i][k].second);
        }
    }
    forto(k,1,n)forto(i,1,n)forto(j,1,n)minto(dist[i][j],dist[i][k]+dist[k][j]);
    int x,y;ll ans;
    while(q--){
        cin>>x>>y;
        ans=INF;
        forv(i,at[x].size())forv(j,at[y].size())minto(ans,dist[at[x][i].first][at[y][j].first]+at[x][i].second+at[y][j].second);
        ans+=w[x]+w[y],cout<<ans<<'\n';
    }
    return 0;
}