#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q;
i64 w[M],dis[N][N];
int ls[M],tot;
struct trans{
    int to,pr;
    i64 t;
}e[M];
void add(int u,int li,int t){
    e[++tot]={li,ls[u],t};
    ls[u]=tot;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=1e18;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;dis[i][i]=0;
        for(int j=1,a,t;j<=k;j++)
            cin>>a>>t,add(a,i,t);
    }
    for(int u=1;u<=m;u++){
        for(int i=ls[u];i;i=e[i].pr){
            int la=e[i].to;
            for(int j=ls[u];j;j=e[j].pr){
                int lb=e[j].to;
                dis[la][lb]=min(dis[la][lb],e[i].t+e[j].t);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        i64 ans=1e18;
        for(int i=ls[x];i;i=e[i].pr){
            int la=e[i].to;
            for(int j=ls[y];j;j=e[j].pr){
                int lb=e[j].to;
                ans=min(ans,dis[la][lb]+e[i].t+e[j].t+w[x]+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
}