#include<bits/stdc++.h>
using namespace std;
int a[10000],b[1000][1000],d[1000][1000],dis[10000];
struct op{
    int st,en;
}c[10000];
struct node{
    int dis,dia;
     friend  operator<node(const node &x,const int dis) {
        return x.dis<dis;
    }
};
bool ved[10000];
priority_queue<node> q;
vector<pair<int,int>> g[10000];
void djstla(int s){
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        node m=q.top();
        q.pop();
        if(ved[m.dia]) continue;
        ved[m.dia]=1;
        for(auto e:g[m.dia]){
            int x=e.first,y=e.second;
            if(dis[x]>=dis[y]+val){
                dis[x]=dis[y]+val;
                q.push({dis[y],y});
            }
        }
    }
}
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        for(int j=1;j<=u;j++){
            cin>>b[i][j]>>d[i][j];
        }
        for(int j=1;j<u;j++){
            g[i].push({b[i][j],b[i+1][j]});
        }
    }
    for(int i=1;i<=p;i++){
        cin>>c[i].st>>c[i].en;
        num=a[c[i].st]+a[c[i].en];
        djstla(c[i].st);
        num+=dis[c[i].en]
    }
    cout<<num;
    return 0;
}
