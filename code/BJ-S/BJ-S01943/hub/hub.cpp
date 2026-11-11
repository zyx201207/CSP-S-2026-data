#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll n,h[N],k,t,id,idi,maxx,dis[N],c;
bool vis[N];
vector<int> vt[N];
void dfs(int x,int fa){
    for(auto y:vt[x]){
        if(y==fa)continue;
        h[y]=h[x]+1;
        dfs(y,x);
    }
}
void tree(){
    dfs(1,0);
    id=0,idi=0,maxx=0;
    for(int i=1;i<=n;i++){
        if(maxx<h[i]){
            id=i;
                maxx=h[i];
            }
            h[i]=0;
        }
        dfs(id,0);
        maxx=0;
        for(int i=1;i<=n;i++){
            if(maxx<h[i]){
                idi=i;
                maxx=h[i];
            }
            h[i]=0;
        }
}
void dfs2(int x,int fa){
    for(auto y:vt[x]){
        if(y==fa)continue;
        if(vis[x&&vis[y]])h[y]=h[x];
        else h[y]=h[x]+1;
        dfs2(y,x);
    }
}
void treee(){
    dfs2(1,0);
    id=0,idi=0,maxx=0;
    for(int i=1;i<=n;i++){
        if(maxx<h[i]){
            id=i;
                maxx=h[i];
            }
            h[i]=0;
        }
        dfs2(id,0);
        maxx=0;
        for(int i=1;i<=n;i++){
            if(maxx<h[i]){
                idi=i;
                maxx=h[i];
            }
            h[i]=0;
        }
}
ll check(ll x){
    tree();
    queue<pair<int,int>> q;
    q.push({id,x});
    q.push({idi,x});
    memset(vis,0,sizeof(vis));
    while(q.size()){
        auto [r,cnt]=q.front();
        q.pop();
        if(vis[r]==1)continue;
        vis[r]=1;
        if(cnt==0)continue;
        for(auto y:vt[r]){
            if(vis[y]==1)continue;
            q.push({y,cnt-1});
            vis[y]=1;
        }
    }
    treee();
    cout<<maxx<<" ";
    return maxx;
}
ll erfen(ll l,ll r){
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)<=k){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            vt[u].push_back(v);
            vt[v].push_back(u);
        }
        dfs(1,0);
        id=0,idi=0,maxx=0;
        for(int i=1;i<=n;i++){
            if(maxx<h[i]){
                id=i;
                maxx=h[i];
            }
            h[i]=0;
        }
        dfs(id,0);
        maxx=0;
        for(int i=1;i<=n;i++){
            if(maxx<h[i]){
                idi=i;
                maxx=h[i];
            }
            h[i]=0;
        }
        //cout<<erfen(1,maxx)<<endl;
        cout<<maxx/k<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
