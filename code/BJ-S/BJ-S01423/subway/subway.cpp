#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int C,n,m,d,q,c[N],k[505],dis[505][505],v[505];
vector<int> a[505],t[505],h[505];
vector<pair<int,int>> p[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];int x,y;
        for(int j=1;j<=k[i];j++){
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            p[x].push_back({i,y});
        }
    }for(int i=1;i<=m;i++)
        if(p[i].size()!=1)
            for(auto x:p[i])
                h[x.first].push_back(i); 
    for(int i=1;i<=n;i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,i}),memset(v,0,sizeof(v)),memset(dis[i],0x3f,sizeof(dis[i])),dis[i][i]=0;
        while(!q.empty()){
            auto u=q.top();q.pop();
            int d=u.first,id=u.second;
            if(v[id])continue;v[id]=1;
            for(int x:h[id]){int l;
                for(auto np:p[x])
                    if(np.first==id)
                        l=np.second;
                for(auto np:p[x])
                    if(np.first!=id&&d+l+np.second<dis[i][np.first]){
                        dis[i][np.first]=d+l+np.second;
                        q.push({dis[i][np.first],np.first});
                    }
            }
        }
    }while(q--){
        int x,y,ans=1e18;cin>>x>>y;
        for(auto i:p[x])for(auto j:p[y])
            ans=min(ans,dis[i.first][j.first]+i.second+j.second);
        cout<<ans+c[x]+c[y]<<"\n";
    }
}