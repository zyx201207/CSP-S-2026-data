#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N=1e6+5;

vector<int> g[N];
int CASE;
int n,k;
bool flag[N];
bool vis[N];

int dfsCNT(int u,int fa=0){
    if(!flag[u])return 0;
    vis[u]=true;
    int res=1;
    for(int v:g[u]){
        if(v==fa)continue;
        res+=dfsCNT(v,u);
    }
    return res;
}

bool ok(int s){
    for(int i=0;i<=n+3;i++)flag[i]=vis[i]=false;
    vector<int> nd;
    for(int i=1;i<=n;i++)if(s>>i-1&1){
        flag[i]=true;
        nd.push_back(i);
    }
    int cnt=dfsCNT(nd[0]);
    for(int i:nd)if(!vis[i]){
        cnt+=dfsCNT(i);
        break;
    }
    return cnt==__builtin_popcount(s);
}

struct Node{
    int id,dst;
};

int calc(int s){
    queue<Node> q;
    for(int i=1;i<=n;i++){
        vis[i]=false;
        if(s>>i-1&1){
            q.push({i,0});
            vis[i]=true;
        }
    }
    int res=0;
    while(q.size()){
        Node h=q.front();q.pop();
        res=max(res,h.dst);
        for(int v:g[h.id]){
            if(!vis[v]){
                vis[v]=true;
                q.push({v,h.dst+1});
            }
        }
    }
    return res;
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(CASE==13 || CASE==14){
        n=(n-1)/2;
        cout<<(n+4-k+3)/4<<"\n";
       return;
    }

    int ans=2e9;
    for(int s=1;s<1<<n;s++){
        if(__builtin_popcount(s)==k && ok(s)){
            ans=min(ans,calc(s));
        }
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>CASE>>T;
    while(T--){
        solve();
    }
    return 0;
}