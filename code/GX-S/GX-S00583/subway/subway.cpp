#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
};
int c,n,m,d,q,w[500100],a[510][500010],t[510][500010],k[510],r[100010][5],ans,z[500100],tt,dis[500100],vis[500100];
bool flag,flag1;
vector<int> g[500010];
void dijk(int s){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    memset(dis,0x3f3f3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    pq.push({s,0});
    dis[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto e:g[u]){
            int v = e,w = 2*tt;
            if(vis[v]) continue;
            if(dis[u]+w<dis[v]){
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
                vis[v] = true;
            }
        }
    }
}
/*
void dfs(int s,int tim,int cnt,int las){
    if(s==r[cnt][2]){
        ans = min(ans,tim);
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i][1]==s){
            if(las==0) tim+=t[i][1];
            else tim+=(t[las][1]+t[i][1]);
            dfs(a[i][2],tim,cnt,i);
            if(las==0) tim-=t[i][1];
            else tim-=(t[las][1]+t[i][1]);
        }
    }
}
*/
int main(){
    /*
    0 2 5 20 2
    4 1 9 2 5
    3 1 5 2 7 4 6
    3 2 3 3 4 5 7
    1 3
    1 2
    */
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway6.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]>2) flag = true;
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            if(i==1&&j==1) tt = t[i][j];
            if(t[i][j]!=tt) flag1 = true;
            z[a[i][j]]++;
        }
    }
    for(int i=1;i<=q;i++) cin>>r[i][1]>>r[i][2];
    if(!flag1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
               if(z[a[i][j]]>1){
                    for(int x=1;x<=k[i];x++){
                        g[a[i][x]].push_back(a[i][j]);
                        g[a[i][j]].push_back(a[i][x]);
                    }
               }
            }
        }
        for(int i=1;i<=q;i++){
            dijk(r[i][1]);
            cout<<dis[r[i][2]]+w[r[i][1]]+w[r[i][2]]-tt<<endl;
        }
    }
    cout<<ans;
    return 0;
}
