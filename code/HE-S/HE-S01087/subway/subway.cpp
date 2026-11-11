#include<bits/stdc++.h>
using namespace std;
using pii=pair<long long,int>;
const int N=5e5+5000;
long long c,n,m,d,q,w[N],k,a,t,ans[550][550],dis[N];
bool ppd[N],vis[N];
long long ths[N],hd[N],nxt[2*N],ver[2*N],ww[2*N],tot;
struct node{
    int op1,op2;
}xx[N];
void add(int u,int v,long long www){
    ver[++tot]=v;nxt[tot]=hd[u];ww[tot]=www;hd[u]=tot;
    ver[++tot]=u;nxt[tot]=hd[v];ww[tot]=www;hd[v]=tot;
}
void dij(int u){
    for(int i=0;i<=N;i++) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,u});
    dis[u]=0;
    while(pq.size()){
        int uu=pq.top().second;pq.pop();
        if(vis[uu]) continue;
        vis[uu]=true;
        for(int i=hd[uu];i;i=nxt[i]){
            int v=ver[i];
            if(dis[uu]+ww[i]<dis[v]){
                dis[v]=dis[uu]+ww[i];
                pq.push({dis[v],v});
            }
        }
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        add(i,m+i,w[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int u;long long t;cin>>u>>t;
            add(m+u,2*m+i,t);
        }
    }
    memset(ppd,0,sizeof(ppd));
    for(int ii=1;ii<=q;ii++){
        cin>>xx[ii].op1>>xx[ii].op2;
        ths[xx[ii].op1]=1;
    }
    for(int ii=1;ii<=m;ii++){
        if(ths[ii]==0) continue;
        memset(vis,0,sizeof(vis));
        dij(ii);
        for(int i=1;i<=m;i++){
            ans[ii][i]=dis[i];
        }
    }
    for(int ii=1;ii<=q;ii++){
        cout<<ans[xx[ii].op1][xx[ii].op2]<<'\n';
    }
	return 0;
}
/*Õâ°ÑÕ¨ÁË¡­ 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

