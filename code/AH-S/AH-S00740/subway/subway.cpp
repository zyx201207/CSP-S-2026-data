#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[500010];
int t;
vector<int> g1[510];
vector<int> g2[500010];
bool vis[500010];
struct node{
    int v,d;
};
void bfs(int s,int t){
    queue<node> q;
    q.push({s,0});
    vis[s]=1;
    while(!q.empty()){
        node now=q.front();
        q.pop();
        if(now.v==t){
            ans=now.d*t;
            return;
        }
        for(int i=0;i<g2[now.v].size();i++){
            for(int j=0;j<g1[g2[now.v][i]].size();j++){
                if(g1[g2[now.v][i]][j]!=now.v&&!vis[g1[g2[now.v][i]][j]]){
                    q.push({g1[g2[now.v][i]][j],now.d+1});
                    vis[g1[g2[now.v][i]][j]]=1;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++){
            int a1;
            cin>>a1;
            cin>>t;
            g1[i].push_back(a1);
            g2[a1].push_back(i);
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        bfs(x,y);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
