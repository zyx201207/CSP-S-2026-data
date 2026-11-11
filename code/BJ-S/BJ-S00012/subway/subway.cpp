#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=505,M=500005,D=25;
int c,n,m,d,q,w[M],cnt[M],dis[N][N];
vector<pair<int,int> > mp[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            mp[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto j:mp[i]){
            for(auto k:mp[i]){
                dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
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
        int l,r,ans=LLONG_MAX;
        cin>>l>>r;
        for(auto j:mp[l]){
            for(auto k:mp[r]){
                ans=min(ans,dis[j.first][k.first]+j.second+k.second);
            }
        }
        cout<<ans+w[l]+w[r]<<'\n';
    }
    return 0;
}