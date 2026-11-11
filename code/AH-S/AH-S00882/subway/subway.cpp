#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[5005];
ll pos[205][5005],ans=0x3f3f3f3f;
bool vis[5005];
ll x,y;
struct node{
    ll next,type;
};
vector<node> g[5005];

void dfs(ll t,ll typ,ll sum){
    if(t==y){
        ans=min(ans,sum+pos[typ][t]);
        return ;
    }
    vis[t]=true;
    for(int i=0;i<g[t].size();i++){
        node tmp=g[t][i];
        if(!vis[tmp.next]){
            if(tmp.type!=typ){
                dfs(tmp.next,tmp.type,sum+pos[typ][t]+pos[tmp.type][tmp.next]);
            }else{
                dfs(tmp.next,tmp.type,sum);
            }
        }
    }
    vis[t]=false;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        int last=-1;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            pos[i][a]=t;
            if(j!=1){
                g[last].push_back({a,i});
                g[a].push_back({last,i});
            }
            last=a;
        }
    }
    while(q--){
        ans=0;memset(vis,0,sizeof vis);
        cin>>x>>y;
        vis[x]=true;
        dfs(x,0,0);
        cout<<w[x]+w[y]+ans<<endl;
    }
    return 0;
}
