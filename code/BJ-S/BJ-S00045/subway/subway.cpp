#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qu;
int w[500005];
struct node{
    int a,b,op;
};
vector<node>v[500005];
int vis[500005][25];
int dis[500005][25];
int ans;
queue<node>q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>qu;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>c;
        int a=0,b,t,l;
        for(int j=1;j<=c;j++){
            cin>>b>>t;
            if(a==0){
                a=b;
                l=t;
            }else{
                v[a].push_back({b,l,i});
                dis[a][i]=v[a].size()-1;
                v[b].push_back({a,t,i});
                dis[b][i]=v[b].size()-1;
                a=b;
                l=t;
            }
        }
    }
    for(int t=1;t<=qu;t++){
        int sx,sy;
        cin>>sx>>sy;
        ans=INT_MAX;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<v[sx].size();i++){
            q.push({sx,v[sx][i].b,v[sx][i].op});
            vis[sx][v[sx][i].op]=v[sx][i].b;
        }
        while(!q.empty()){
            int x=q.front().a,t=q.front().b,op=q.front().op;
            q.pop();
            if(x==sy){
                ans=min(ans,t+v[sy][dis[sy][op]].b+w[sx]+w[sy]);
                continue;
            }
            for(int i=0;i<v[x].size();i++){
                int nxt=v[x][i].a,nop=v[x][i].op;
                if(nop!=op){
                    int ct=t+v[x][dis[x][op]].b+v[x][dis[x][nop]].b;
                    if(vis[nxt][nop]==0||vis[nxt][nop]>ct){
                        vis[nxt][nop]=ct;
                        q.push({nxt,ct,nop});
                    }
                }else{
                    int ct=t;
                    if(vis[nxt][op]==0||vis[nxt][op]>ct){
                        vis[nxt][op]=ct;
                        q.push({nxt,ct,op});
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
