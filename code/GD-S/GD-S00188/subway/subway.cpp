#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define infll 1000000000000000000ll
using namespace std;
namespace FastIO{
    char bufin[1<<20],*fs,*ft;
    char getc(){
        return (fs==ft&&(ft=(fs=bufin)+fread(bufin,1,1<<20,stdin),fs==ft))?EOF:*fs++;
    }
    template<class T>
    void read(T& x){
        x=0;
        int f=1;
        char ch=getc();
        while(ch<'0'||ch>'9'){
            if(ch=='-') f=-1;
            ch=getc();
        }
        while(ch>='0'&&ch<='9'){
            x=10*x+(ch-'0');
            ch=getc();
        }
        if(f==-1) x=-x;
    }
}
using FastIO::read;
const int N=505,M=500005;
int n,m,q;
int w[M];
vector<PII>mp[M];
ll dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,d;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        read(w[i]);
    for(int i=1;i<=n;i++){
        int len;
        read(len);
        for(int j=1,x,y;j<=len;j++){
            read(x),read(y);
            mp[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=(i==j?0:infll);
    for(int i=1;i<=m;i++){
        for(PII x:mp[i])
            for(PII y:mp[i]){
                int u=x.first,v=y.first,w=x.second+y.second;
                dis[u][v]=min(dis[u][v],0ll+w);
                dis[v][u]=min(dis[v][u],0ll+w);
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1,u,v;i<=q;i++){
        read(u),read(v);
        ll res=infll;
        for(PII x:mp[u])
            for(PII y:mp[v])
                res=min(res,dis[x.first][y.first]+x.second+y.second);
        printf("%lld\n",res+w[u]+w[v]);
    }
}