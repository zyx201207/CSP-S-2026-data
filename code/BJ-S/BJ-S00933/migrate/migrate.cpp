#include<bits/stdc++.h>
#define N 5010
#define int long long
using namespace std;

int c,t;
int cnt[N];
vector<int> g[N];

struct Node{
    int pos,val;
};

void bfs(int st){
    queue<Node> q;
    q.push({st,0});
    int v[N]={};
    memset(v,0x3f,sizeof v);
    v[st]=0;
    while(q.size()!=0){
        Node t=q.front();
        q.pop();
        for(int i=0;i<g[t.pos].size();i++){
            if(v[g[t.pos][i]]>=v[t.pos]+1){
                if(v[g[t.pos][i]]>v[t.pos]+1) cnt[g[t.pos][i]]=1;
                else cnt[g[t.pos][i]]++;
                q.push({g[t.pos][i],t.val+1});
                v[g[t.pos][i]]=v[t.pos]+1;
            }
        }
    }
}

void solve(){
    int n,m,a[N]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) g[i].clear();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]>m) break;
            g[i].push_back(j);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof cnt);
        bfs(i);
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(cnt[j]==2) ans++;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
