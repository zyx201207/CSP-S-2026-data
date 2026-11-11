#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005],a[500005],t[500005];
struct node{
    int v;
    ll z;
};
struct node2{
    int h;
    ll z;
    bool operator <(const node2 x)const{
        return z>x.z;
    }
};
vector<node> tr[500005];
ll dis[500005];
bool vis[500005];
void dij(int st){
    memset(dis,0x7f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<node2> q;
    q.push({st,0});
    dis[st]=0;
    while(!q.empty()){
        node2 T=q.top();
        q.pop();
        vis[T.h]=1;
        for(auto z:tr[T.h]){
            int v=z.v;
            int va=z.z;
           // cout<<T.h<<" "<<dis[T.h]<<" "<<va<<" "<<v<<" "<<dis[v]<<'\n';
            if(dis[T.h]+va<=dis[v]&&vis[v]==0){
                dis[v]=dis[T.h]+va;
                q.push({v,dis[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int x,n,m,d,q;
    cin>>x>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int K;
        cin>>K;
        for(int j=1;j<=K;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=K;j++){
            for(int k=j+1;k<=K;k++){
                tr[a[j]].push_back({a[k],t[j]+t[k]});
                tr[a[k]].push_back({a[j],t[j]+t[k]});
                //cout<<a[j]<<" "<<a[k]<<" "<<t[j]+t[k]<<'\n';
            }
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<0;
            continue;
        }
        dij(l);
        cout<<dis[r]+w[l]+w[r]<<'\n';
    }
    return 0;
}
