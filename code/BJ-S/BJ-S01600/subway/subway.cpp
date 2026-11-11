#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n,m;
long long w[500005];
long long k[500005];
//然后定义g,存边
long long zhan_to_xian[510][int(2*1e4)+10];
long long a[510][int(2*1e4)+10];
vector<pair<int,long long> > zx[500005];//线路-时间
long long t[510][int(2*1e4)+10];
long long dis[500005];//dis[i]统一表示到i站台！
int vis[500005];
struct node{
    int u;
    long long disu;
    friend bool operator <(node x,node y){
        return x.disu>y.disu;
    }
};
int x,y,c,d,q;
void dij(int start){
    for(int i=1;i<=m;i++){
        dis[i]=1e18;
        vis[i]=0;
    }
    dis[start]=0;
    priority_queue<node> q;
    q.push({start,0});
    while(q.size()){
        int u=q.top().u;
        int disu=q.top().disu;
        q.pop();
        //cout<<"走到第"<<u<<"站台了\n";
        if(u==y){
            //cout<<"完美走到y";
            cout<<dis[u]+w[start]+w[u]<<endl;
            return ;
        }
        //if(vis[u])cout<<"之前已经走过了，跳过";
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<zx[u].size();i++){
            //枚举可以前往的线路
            int go_xianlu=zx[u][i].first;
            long long w=zx[u][i].second;
            //cout<<"检测到可以去"<<go_xianlu<<"号线\n";
            //那就去那个线路
            for(int j=1;j<=k[go_xianlu];j++){
                int v=a[go_xianlu][j];//可以到达这个站
                long long ww=t[go_xianlu][j];//进主站
                //cout<<"那就可以去"<<v<<"站，时长分为到u的站台，然后再从v的站台进去("<<w<<"+"<<ww<<"="<<w+ww<<")";
                if(dis[v]>dis[u]+w+ww){
                    //cout<<"此方案更优\n"<<"原方案"<<dis[v]<<"现在的方案："<<dis[u]<<"+"<<w<<"+"<<ww<<"="<<dis[u]+w+ww<<"更快\n";
                    dis[v]=dis[u]+w+ww;
                    q.push({v,dis[v]});
                }else{
                    //cout<<"原方案更优\n"<<"原方案"<<dis[v]<<"现在的方案："<<dis[u]<<"+"<<w<<"+"<<ww<<"="<<dis[u]+w+ww<<"更慢\n";
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
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            long long cs;
            cin>>a[i][j]>>cs;
            t[i][j]=cs;
            //怎么知道i站到那一个线路呢？
            zx[a[i][j]].push_back({i,cs});//这个地铁站记录自己在几号线上
        }
    }
    while(q--){
        cin>>x>>y;
        dij(x);
    }
    return 0;
}
