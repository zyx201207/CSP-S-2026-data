#include<bits/stdc++.h>

using namespace std;
//O(m^3) 44pts?
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=2e5+10;

ll dis[2000][2000];
vector<pii>mp[N];
ll w[2000];
int c,n,m,d,q,k;
ll a[2000];
ll t[2000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        dis[i][i]=0;
    }
    int x,y;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int qq=1;qq<=k;qq++){
            for(int pp=1;pp<=k;pp++){
                if(qq==pp)continue;
                dis[a[qq]][a[pp]]=min(t[pp]+t[qq],dis[a[pp]][a[qq]]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        if(x==y){
            cout<<0<<'\n';
        }
        else{
            cout<<w[x]+w[y]+dis[x][y]<<'\n';
        }
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
#include<bits/stdc++.h>

using namespace std;
//O(m^3) 44pts?
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;

const int N=5e5+10;

map<pii,ll>dis;
vector<pli>mp[N+1000];
ll w[N];
int c,n,m,d,q,k;
ll a[N];
ll t[N];
ll diss[N];
bitset<N>vis;
inline void dij(int s,int t){
    priority_queue<pli,vector<pli>,greater<pli>>q;
    memset(diss,0x3f,sizeof(diss));
    vis.reset();
    q.push({0,s});
    dis[{s,s}]=0;
    diss[s]=0;
    int u;
    while(!q.empty()){
        u=q.top().second;
        q.pop();
        dis[{min(u,s),max(u,s)}]=diss[u];
        vis[u]=1;
        for(auto e:mp[u]){
            int x,y;
            x=min(s,e.second);
            y=max(s,e.second);
            if(dis.find({x,y})==dis.end()){
                continue;
            }
            if(vis[e.second]){
                continue;
            }
            if(diss[e.second]>diss[u]+e.first){
                diss[e.second]=diss[u]+e.first;
                q.push({diss[e.second],e.second});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("subway.in","r",stdin);
    // freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int x,y;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            mp[i+m].push_back({y,x});
            mp[x].push_back({y,i+m});
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        if(x==y){
            cout<<0<<'\n';
        }
        else{
            if(x>y)swap(x,y);
            if(dis.find({x,y})!=dis.end()){
                cout<<dis[{x,y}]+w[x]+w[y]<<'\n';
            }
            else{
                dij(x,y);
                cout<<dis[{x,y}]+w[x]+w[y]<<'\n';
            }
        }    
    }
    return 0;
}
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/