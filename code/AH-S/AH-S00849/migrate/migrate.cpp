#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005],d;
vector<int> g[2000005];
bool vis[2000005];
int dis[2000005];
int way[2000005];
long long BFS(int st){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        vis[i]=0,dis[i]=-1,way[i]=0;
    }
    queue<int> q;
    vis[st]=1,dis[st]=0;
    q.push(st);
    while(!q.empty()){
        int u=q.front();q.pop();
      //  cout<<u<<':';
        for(int v:g[u]){
          //      cout<<v<<' ';
            if(!vis[v]){
                dis[v]=dis[u]+1;
                vis[v]=1;
                q.push(v);
                way[v]=1;
            }else{
                if(dis[v]==dis[u]+1){
                    way[v]++;
                    if(way[v]==2) cnt++;
                    if(way[v]==3) cnt--;
                }
            }
        }
        //cout<<endl;
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
        scanf("%d %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        int l=1;
        for(int r=2;r<=n;r++){
            while(x[r]-x[l]>d) l++;
            for(int i=l;i<r;i++){
                g[i].push_back(r);
            }
        }
        /*for(int i=1;i<=n;i++){
            cout<<i<<':';
            for(auto v:g[i]){
                cout<<" to"<<v<<endl;
            }
        }*/
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=BFS(i);
        }
        cout<<ans<<endl;
        /*for(int i=1;i<=n;i++){
            cout<<dis[i]<<' ';
        }
        cout<<endl;*/
    }
    return 0;
}
