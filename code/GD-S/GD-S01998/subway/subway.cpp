#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<int,int>;
using Pll=pair<ll,int>;
void solveA(){
    int p,n,D,q;
    cin>>p>>n>>D>>q;
    vector<int> W(n+1);
    for(int i=1;i<=n;i++) cin>>W[i];
    vector<vector<P>> g(n+1);
    for(int i=1;i<=p;i++){
        int k;
        cin>>k;
        if(k==1){
            int qwer,wert;
            cin>>qwer>>wert;
        }
        else{
            int u1,t1,u2,t2;
            cin>>u1>>t1>>u2>>t2;
            g[u1].push_back({u2,t1+t2});
            g[u2].push_back({u1,t1+t2});
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        priority_queue<Pll,vector<Pll>,greater<>> pq;
        pq.push({0,s});
        vector<ll> dis(n+1,1e18);
        dis[s]=0;
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dis[u]) continue;
            for(auto [v,w]:g[u])
                if(dis[v]>dis[u]+w)
                    pq.push({dis[v]=dis[u]+w,v});
        }
        cout<<dis[e]+W[s]+W[e]<<'\n';
    }
}
void solve(){
    int p,n,D,q;
    cin>>p>>n>>D>>q;
    vector<int> W(n+1);
    for(int i=1;i<=n;i++) cin>>W[i];
    vector<vector<ll>> dis(n*(p+1)+1,vector<ll>(n*(p+1)+1,1e18));
    for(int i=1;i<=n*(p+1);i++) dis[i][i]=0;
    for(int i=1;i<=p;i++){
        int k;
        cin>>k;
        int fa;
        for(int j=1;j<=k;j++){
            int u;
            ll t;
            cin>>u>>t;
            dis[u][u+i*n]=t;
            dis[u+i*n][u]=t;
            if(j!=1){
                dis[u+i*n][fa+i*n]=0;
                dis[fa+i*n][u+i*n]=0;
            }
            fa=u;
        }
    }
    for(int k=1;k<=n*(p+1);k++)
        for(int i=1;i<=n*(p+1);i++)
            for(int j=1;j<=n*(p+1);j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+W[x]+W[y]<<'\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int c;
    cin>>c;
    if(7<=c&&c<=11) solveA();
    else solve();
    return 0;
}