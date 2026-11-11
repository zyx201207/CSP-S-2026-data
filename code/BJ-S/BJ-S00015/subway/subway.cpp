#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+10;

ll read(){
    ll num=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        num=num*10+c-'0';
        c=getchar();
    }
    return num*f;
}

ll c,n,m,d,q,w[N],ans;
ll dis[505][505];
struct node{
    ll id,t;
};
vector <node> bel[N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            int id;
            ll t;
            id=read();
            t=read();
            bel[id].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<bel[i].size();j++){
            for(int k=j+1;k<bel[i].size();k++){
                int id1=bel[i][j].id,id2=bel[i][k].id;
                dis[id1][id2]=dis[id2][id1]=min(dis[id1][id2],bel[i][j].t+bel[i][k].t);
            }
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        ans=9e18;
        int u=read(),v=read();
        for(int i=0;i<bel[u].size();i++){
            for(int j=0;j<bel[v].size();j++){
                ans=min(ans,w[u]+w[v]+bel[u][i].t+bel[v][j].t+dis[bel[u][i].id][bel[v][j].id]);
            }
        }
        cout<<ans<<'\n';
    }
}
