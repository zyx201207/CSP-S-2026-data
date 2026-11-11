#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,n,m,d,q,k;
LL w[500010];
struct str{
    LL a,t;
}N,M;
vector<str> v[500010];
vector<str> line[510];
LL s,f;
LL x;
bool vis[500010];
LL dis[500010];
priority_queue<LL,vector<LL>,greater<LL> > dui;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            scanf("%lld%lld",&N.a,&N.t);
            M.a=i;
            M.t=N.t;
            v[M.a].push_back(M);
            line[i].push_back(N);
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        scanf("%lld%lld",&s,&f);
        dis[s]=0;
        dui.push(s);
        while(!dui.empty()){
            x=dui.top();
            dui.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(int i=0;i<v[x].size();i++){
                N=v[x][i];
                for(int j=0;j<line[N.a].size();j++){
                    if(!vis[line[N.a][j].a]&&dis[x]+N.t+line[N.a][j].t<dis[line[N.a][j].a]){
                        dis[line[N.a][j].a]=dis[x]+N.t+line[N.a][j].t;
                        dui.push(line[N.a][j].a);
                        //cout<<line[N.a][j].a<<" ";
                    }
                }
            }
        }
        printf("%lld\n",dis[f]+w[s]+w[f]);
    }
    return 0;
}
