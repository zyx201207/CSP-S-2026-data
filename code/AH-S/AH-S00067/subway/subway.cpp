#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,w;
    bool operator<(const node s)const{
        return s.w<w;
    }
};
struct line{
    int a,t;
};
vector<node> g[500005];
int c,n,m,d,q;
int w[500005];
vector<line> l[505];
int a[5][500005];
int minn=1e9;
bool vis[200005];
int dis[200005];
void dij(int s,int ed){
    priority_queue<node> q;
    q.push({s,0});
    for(int i=1;i<=m;i++){
        dis[i]=2147483647;
    }
    dis[s]=0;
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        if(vis[tmp.to]==1){
            continue;
        }
        vis[tmp.to]=1;
        int pos=tmp.to;
        for(int i=0;i<g[pos].size();i++){
            node u=g[pos][i];
            if(vis[u.to]==1){
                continue;
            }
            dis[u.to]=min(dis[u.to],tmp.w+u.w);
            q.push({u.to,dis[u.to]});
        }
    }
    cout<<w[s]+dis[ed]+w[ed]<<endl;
}
void add(int pos1,int pos2,int li){
    int cost=l[li][pos1].t+l[li][pos2].t;
    g[pos1].push_back({pos2,cost});
    g[pos2].push_back({pos1,cost});
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        l[i].push_back({k,-1});
        for(int j=1;j<=l[i][0].a;j++){
            int aa,tt;
            cin>>aa>>tt;
            l[i].push_back({aa,tt});
        }
    }
    if(c>=20&&c<=21){
        memset(a,-1,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=l[i][0].a;j++){
                a[i][l[i][j].a]=l[i][j].t;
            }
        }
        for(int i=1;i<=m;i++){
            if(a[1][i]!=-1&&a[2][i]!=-1){
                minn=min(minn,a[1][i]+a[2][i]);
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            int ans=0;
            if(a[1][x]!=-1&&a[1][y]!=-1){
                ans=w[x]+a[1][x]+a[1][y]+w[y];
            }else if(a[2][x]!=-1&&a[2][y]!=-1){
                ans=w[x]+a[2][x]+a[2][y]+w[y];
            }else{
                if(a[1][x]!=-1){
                    ans=w[x]+a[1][x]+minn+a[2][y]+w[y];
                }else{
                    ans=w[x]+a[2][x]+minn+a[1][y]+w[y];
                }
            }
            cout<<ans<<endl;
        }
    }else if(c>=1&&c<=8){

        for(int i=1;i<=n;i++){
            for(int j=1;j<=l[i][0].a;j++){
                for(int k=1;k<=l[i][0].a;k++){
                    if(j!=k)
                        add(j,k,i);
                }
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            dij(x,y);
        }
    }
    return 0;
}
