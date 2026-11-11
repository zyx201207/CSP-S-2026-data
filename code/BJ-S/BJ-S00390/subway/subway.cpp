#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll x,y;
};
ll w[500010],k[510][30],k2[510][30],f[510][510];
vector<node>v[1000010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    ll c,n,m,d,q,x,y,z,ans,ans2;
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        cin>>k[i][0];
        for(int j=1;j<=k[i][0];j++){
            cin>>x>>y;k[i][j]=x,k2[i][j]=y;
            if(v[x].size())for(auto j2:v[x]){
                f[j2.x][i]=f[i][j2.x]=min(f[i][j2.x],j2.y+y);
            }
            v[x].push_back({i,y});
        }
    }
    for(int k=1;k<=m;k++)for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)if(f[i][j]>f[i][k]+f[k][j])f[i][j]=f[i][k]+f[k][j];
    while(q--){
        cin>>x>>y;ans=1e18;
        for(auto i:v[x])for(auto j:v[y]){ ans=min(ans,f[i.x][j.x]+i.y+j.y); }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}