#include<bits/stdc++.h>
using namespace std;
struct node{
    int nxt;
    int time;
};
int c,n,m,d,q,w[500505];
vector<node>g[500505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    int kk[500505];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        kk[i]=k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[i].push_back({500+a,t});
            g[500+a].push_back({i,t});
            kk[500+a]++;
        }
    }while(q--){
        int vis[500505],dis[500505];
        for(int i=1;i<=500+m;i++){
            vis[i]=0;
            dis[i]=1e9;


        }
        int s,e;
        cin>>s>>e;
        queue<int>qq;
        qq.push(500+s);
        dis[500+s]=0;
        while(!qq.empty()){
            int t=qq.front();
            qq.pop();

            for(auto x:g[t]){

                if(vis[x.nxt]<=kk[x.nxt]&&x.nxt!=500+s){
                    qq.push(x.nxt);
                    dis[x.nxt]=min(dis[x.nxt],dis[t]+x.time);
vis[x.nxt]++;
                }
            }
        }
        cout<<w[s]+w[e]+dis[500+e]<<endl;
    }
    return 0;
}