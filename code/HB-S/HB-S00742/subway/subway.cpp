#include <bits/stdc++.h>
using namespace std;
namespace fastio{
   template<typename T>
   inline void read(T& x){
    x=0;T f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
   }
   template<typename T>
   inline void write(T x){
    if(x<0){putchar('-');x=-x;}
    if(x>9){write(x/10);}
    putchar('0'+x%10);
   }
}
using namespace fastio;
using ll=long long ;
const int N=1e7+7;
const int M=1e6+7;
int head[N];
int disto[N];//daozhantai
struct{int nex;int v;int w;}E[N<<1];
int cnt=0;
ll tot=0;
void add(int u,int v,int w){
     E[++cnt]={head[u],v,w};
     head[u]=cnt;
}

ll dist[N];

void Dijikstra(int begin){
     memset(dist,0x3f,sizeof(dist));
     dist[begin]=0;
     priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>q;
     q.push({0,begin});
     while(!q.empty()){
      pair<ll,int>now=q.top();
      q.pop();
      ll d=now.first;
      int u=now.second;
      if(d>dist[u]){continue;}
      for(int i=head[u];i;i=E[i].nex){
         int v=E[i].v;
         int w=E[i].w;
         if(d+w<dist[v]){dist[v]=d+w;q.push({dist[v],v});}
      }
     }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,m,c,d,q;
    read(c);read(n);read(m);read(d);read(q);
    tot=m+1;
    for(int i=1;i<=m;i++){
     read(disto[i]);
    }
    for(int i=1;i<=n;i++){
     int k;
     read(k);
     int pre,sw;
     read(pre),read(sw);
     add(++tot,pre,sw);
     add(pre,tot,sw);
     pre=tot;
     for(int j=1;j<k;j++){
      int v,w;
      read(v);read(w);
      add(++tot,v,w);
      add(v,tot,w);
      add(pre,tot,0);
      add(tot,pre,0);
      pre=tot;
    }
    }
    for(int i=1;i<=q;i++){
     int a,b;
     read(a);read(b);
     Dijikstra(a);
     write(dist[b]+disto[a]+disto[b]);
     putchar('\n');
    }
    return 0;
}
