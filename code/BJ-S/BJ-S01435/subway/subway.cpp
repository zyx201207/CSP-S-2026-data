#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,t,x,y,ans,a[500100],f[500100],h[500100],ks,kbl;
struct node{
    int x,y;
};
vector<node> g[510];
vector<int> vis[500100];
map<pair<int,int>,int> mp;
map<pair<int,int>,int> kkk;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t;
        for(int j=1;j<=t;j++){
            cin>>x>>y;
            g[i].push_back({x,y});
            kkk[{i,x}]=y;
            vis[x].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:vis[i]){
            for(auto q:vis[i]){
                if(j==q){
                    continue;
                }
                if(!mp.count({j,q})){
                    mp[{j,q}]=kkk[{j,i}]+kkk[{q,i}];
                }else{
                    mp[{j,q}]=min(mp[{j,q}],kkk[{j,i}]+kkk[{q,i}]);
                }
                mp[{q,j}]=mp[{j,q}];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(k!=i and k!=j){
                    mp[{i,j}]=min(mp[{i,j}],mp[{i,k}]+mp[{j,k}]);
                    mp[{j,i}]=mp[{i,j}];
                }
            }
        }
    }
    while(q--){
        cin>>x>>y;
        memset(f,0,sizeof(f));
        memset(h,0,sizeof(h));
        ans=INT_MAX;
        for(auto i:vis[x]){
            f[i]=kkk[{i,x}];
        }
        for(auto i:vis[y]){
            h[i]=kkk[{i,y}];
        }
        for(auto i:vis[x]){
            for(auto j:vis[y]){
                if(mp[{i,j}]<=ans){
                    ans=mp[{i,j}];
                    ks=i;
                    kbl=j;
                }
            }
        }
        cout<<ans+a[x]+a[y]+kkk[{ks,x}]+kkk[{kbl,y}]<<endl;//zdjd
    }
    return 0;
}
