#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,v[505][505],a[500005],k[505];
vector<pair<int,int> > t2[500005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x,y;j<=k[i];j++){
            cin>>x>>y;
            t2[x].push_back({i,y});
        }
    }
    memset(v,0x3f,sizeof v);
    for(int i=1;i<=n;i++)v[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto it1:t2[i]){
            for(auto it2:t2[i]){
                v[it1.first][it2.first]=min(v[it1.first][it2.first],it1.second+it2.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i==k||v[i][k]>1e15)continue;
            for(int j=1;j<=n;j++)v[i][j]=min(v[i][j],v[i][k]+v[j][k]);
        }
    }
    while(q--){
        int x,y,ans=1e18;
        cin>>x>>y;
        for(auto it1:t2[x]){
            for(auto it2:t2[y]){
                ans=min(ans,it1.second+it2.second+v[it1.first][it2.first]);
            }
        }
        cout<<ans+a[x]+a[y]<<"\n";
    }
    return 0;
}
