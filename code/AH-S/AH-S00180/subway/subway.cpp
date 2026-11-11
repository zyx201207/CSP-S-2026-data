#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
unsigned short c;
int n,m,d,q,w[500001],s[100000],e[100000],mint=2147483647;
bool vis[500001];
struct r{
    int node,timer;
};
vector<int>l[501],t[501],nd[500001];
void bfs(int non,int ti,int des){
    queue<r>q;
    q.push({non,ti});
    while(!q.empty()){
        r h=q.front();
        q.pop();
        if(h.node==des){
            mint=min(h.timer,mint);
            return;
        }
        for(int i=0;i<nd[h.node].size();i++){
            for(int j=1;j<=l[nd[h.node][i]][0];j++){
                if((!vis[l[nd[h.node][i]][j]])&&(nd[l[nd[h.node][i]][j]].size()>1||l[nd[h.node][i]][j]==des)){
                    vis[l[nd[h.node][i]][j]]=1;
                    q.push({l[nd[h.node][i]][j],h.timer+t[h.node][nd[h.node][i]]+t[l[nd[h.node][i]][j]][nd[h.node][i]]});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        l[i].push_back(k);
        for(int j=0,p,o;j<k;j++)cin>>p>>o,l[i].push_back(p),t[p].push_back(o),nd[p].push_back(i);
    }
    for(int i=0;i<q;i++){
        cin>>s[i]>>e[i];
        vis[s[i]]=1;
        bfs(s[i],w[s[i]]+w[e[i]],e[i]);
        cout<<mint;
        mint=2147483647;
        memset(vis,0,sizeof vis);
    }
    return 0;
}
