#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005];
ll len[505][505];
vector<pair<ll,ll>> v[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(len,0x3f,sizeof(len));
    for(ll i=1;i<=n;i++)len[i][i]=0;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1,siz;i<=n;i++){
        cin>>siz;
        for(ll j=1,u1,v1;j<=siz;j++){
            cin>>u1>>v1;
            for(auto k:v[u1]){
                len[i][k.first]=min(len[i][k.first],v1+k.second);
                len[k.first][i]=min(len[k.first][i],v1+k.second);
            }
            v[u1].push_back({i,v1});
        }
    }
    for(ll i=1;i<=n;i++)
        for(ll k=1;k<=n;k++)
            for(ll j=1;j<=n;j++)
                len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
    for(ll i=1,u1,v1;i<=q;i++){
        cin>>u1>>v1;
        ll ans=1e18,bas=w[u1]+w[v1];
        for(auto i1:v[u1]){
            for(auto i2:v[v1]){
                ans=min(ans,bas+len[i1.first][i2.first]+i1.second+i2.second);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
