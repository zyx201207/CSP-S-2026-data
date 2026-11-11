#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair < int,int > pii;
int c,t,n,k,ans,rt,dep[1000005],rdep[1000005],maxdep;
vector < int > to[1000005];
bool flag[1000005],vis[1000005];
queue < int > q;
vector < pii > maxn;
void dfs(int u){
    vis[u]=true;
    for(int v:to[u]){
        if(flag[v]&&!vis[v]) dfs(v);
    }
}
int bfs(int st){
    while(!q.empty()) q.pop();
    q.push(st);
    vis[st]=true;
    int steps=0;
    while(!q.empty()){
        int len=q.size();
        for(int i=1;i<=len;i++){
            int u=q.front();
            q.pop();
            if(flag[u]) return steps;
            for(int v:to[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        steps++;
    }
    return 1e9;
}
void dfs2p(int fa,int u){
    dep[u]=0;
    rdep[u]=rdep[fa]+1;
    for(int v:to[u]){
        if(v!=fa){
            dfs2p(u,v);
            if(u==rt) maxn.push_back({dep[v],v});
            dep[u]=max(dep[u],dep[v]);
        }
    }
    dep[u]++;
}
void dfs2(int fa,int u){
    for(int v:to[u]){
        if(v!=fa) dfs2(u,v);
    }
    if(u!=rt){
        int r;
        if(maxn.back().second==u) r=maxn[maxn.size()-2].first;
        else r=maxn.back().first;
        ans=min(ans,max(max(r,dep[u]),(rdep[u]-1)/2+(rdep[u]-1)%2));
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        if(c==7){
            rt=1;
            for(;rt<=n;rt++){
                maxn.clear();
                maxn.push_back({0,0});
                dfs2p(0,rt);
                sort(maxn.begin(),maxn.end());
                dfs2(0,rt);
            }
            cout<<ans<<endl;
        }
        else{
            for(int dp=0;dp<(1<<n);dp++){
                int r=0;
                for(int i=1;i<=n;i++) vis[i]=false;
                for(int i=0;i<n;i++){
                    flag[i+1]=!!((1<<i)&dp);
                    r+=flag[i+1];
                }
                int cnt=0;
                for(int i=1;i<=n;i++){
                    if(flag[i]&&!vis[i]){
                        dfs(i);
                        cnt++;
                    }
                }
                if(cnt>2||r!=k) continue;
                int maxn=0;
                for(int i=1;i<=n;i++){
                    for(int i=1;i<=n;i++) vis[i]=false;
                    maxn=max(maxn,bfs(i));
                }
                ans=min(ans,maxn);
            }
            cout<<ans<<endl;
        }
        for(int i=1;i<=n;i++) to[i].clear();
    }
}