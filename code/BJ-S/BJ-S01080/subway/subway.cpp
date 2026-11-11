#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<long long,int>;
ll a[505],mp[505][505],dp[505][505],dis[505][505];
ll c,n,m,d,q;
bool st[505];
void dij(int s){
    priority_queue<pii,vector<pii>,greater<pii> > q;
    memset(st,false,sizeof st);
    q.push({0,s});
    dis[s][s]=0;
    st[s]=true;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        st[u]=true;
        for(int i=1;i<=m;i++){
            int w=mp[u][i],v=i;
            if(w==1e18) continue;
            if(st[v]) continue;
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                q.push({dis[s][v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        for(int j=1;j<=m;j++){
            mp[i][j]=1e9;
            dp[i][j]=1e9;
            dis[i][j]=1e9;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int aa[500005];
        ll t[500005];
        for(int j=1;j<=k;j++){
            cin>>aa[j]>>t[j];
        }
        for(int u=1;u<=k;u++){
            for(int v=u;v<=k;v++){
                mp[aa[u]][aa[v]]=min(mp[aa[u]][aa[v]],t[u]+t[v]);
                mp[aa[v]][aa[u]]=mp[aa[v]][aa[u]];
            }
        }
    }
    for(int i=1;i<=m;i++){
        dij(i);
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<dis[u][v]+a[u]+a[v]<<endl;
    }
}
