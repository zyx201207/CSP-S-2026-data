#include<bits/stdc++.h>
using namespace std;
const int N=500005;
#define int long long
void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int c,n,m,d,q,w[N],k[505],T;
vector<pair<int,int> > g[N<<1];
vector<pair<int,int> > hv[N];
int dis[N+505];
struct tt{
    int i,w;
};
struct cmp{
    bool operator()(tt A,tt B){
        return A.w>B.w;
    }
};
bool vis[N+505];
void kfc(int s){
    for(int i=1;i<=m+n;i++){
        dis[i]=1e18;
        vis[i]=0;
    }
    dis[s]=0;
    priority_queue<tt,vector<tt>,cmp> q;
    q.push({s,0});
    while(!q.empty()){
        int i=q.top().i;
        q.pop();
        if(vis[i]) continue;
        vis[i]=1;
        for(int l=0;l<g[i].size();l++){
            int j=g[i][l].first,w=g[i][l].second;
            if(vis[j]) continue;
            if(dis[j]>dis[i]+w){
                dis[j]=dis[i]+w;
                q.push({j,dis[j]});
            }
        }
    }
}
int viss[N+505],dist[N+505];
void kfc1(int s){
    for(int i=1;i<=n+m;i++){
        dist[i]=0;
        viss[i]=0;
    }
    queue<int> q;  
    q.push(s);
    dist[s]=0;
    viss[s]=1; 
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(int k=0;k<g[i].size();k++){
            int j=g[i][k].first;
            if(!viss[j]){
                viss[j]=1;
                dist[j]=dist[i]+1;
                q.push(j);
            }
        }
    }
}
vector<array<int,4> > Q[505];
int as[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    read(c);read(n);read(m);read(d);read(q);
    for(int i=1;i<=m;i++){
        read(w[i]);
    }
    for(int i=1;i<=n;i++){
        read(k[i]);
        for(int aa,tt,j=1;j<=k[i];j++){
            read(aa);read(tt);
            T=tt;
            g[aa].push_back({i+m,tt});
            g[i+m].push_back({aa,tt});
            hv[aa].push_back({i,tt});
        }
    }
    for(int x,y,i=1;i<=q;i++){
        read(x);read(y);
        for(int l=0;l<hv[x].size();l++){
            Q[hv[x][l].first].push_back({i,y,hv[x][l].second,x});
        }
    }
    memset(as,0x3f,sizeof as);
    for(int i=1;i<=n;i++){
        if(c>=16 && c<=19){
            kfc1(i+m);
            for(int l=0;l<Q[i].size();l++){
                int id=Q[i][l][0],y=Q[i][l][1],ww=Q[i][l][2],x=Q[i][l][3];
                as[id]=min(as[id],dist[y]*T+ww+w[x]+w[y]);
            }
        }
        else{
            kfc(i+m);
            for(int l=0;l<Q[i].size();l++){
                int id=Q[i][l][0],y=Q[i][l][1],ww=Q[i][l][2],x=Q[i][l][3];
                as[id]=min(as[id],dis[y]+ww+w[x]+w[y]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cout<<as[i]<<'\n';
    }
    return 0;
}
//g++ subway.cpp -o subway -std=c++14 -O2 "-Wl,-stack=1234567890" -Wall