#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=500+9;
const int M=5e5+9;
ll c,n,m,d,q,x,y;
ll k[N],wk[M],zza,zzt;
ll lx[N][N],err;
struct zhan{
    ll to,t;
};
vector<zhan> z[M];
ll dis[N][N],vis[N][N];
struct node{
    ll u,dis;
    friend bool operator<(node x,node y){
        return x.dis>y.dis;
    }
};
struct b{
    ll v,w;
};
vector<b> dt[N];
void dij(int s){
    priority_queue<node> dl;
    while(!dl.empty()) dl.pop();
    for(int i=1;i<=n;i++) dis[s][i]=1e18;
    dis[s][s]=0;
    vis[s][s]=1;
    dl.push({s,0});
    while(!dl.empty()){
        ll u=dl.top().u,w=dl.top().dis;
        dl.pop();
        for(auto v:dt[u]){
            if(dis[s][v.v]>dis[s][u]+v.w){
                dis[s][v.v]=dis[s][u]+v.w;
            }
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!//
            if(vis[s][v.v]==0){
                vis[s][v.v]=1;
                dl.push({v.v,dis[s][v.v]});
            }
        }
    }
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>wk[i];

	for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>zza>>zzt;
            z[zza].push_back({i,zzt});
        }
	}


	memset(lx,0x3f,sizeof(lx));
	err=lx[1][1];
	for(int k=1;k<=m;k++)
        for(int i=0;i<z[k].size();i++)
            for(int j=0;j<z[k].size();j++){
                if(i==j) continue;
                lx[z[k][i].to][z[k][j].to]=min(z[k][i].t+z[k][j].t,lx[z[k][i].to][z[k][j].to]);
                lx[z[k][j].to][z[k][i].to]=lx[z[k][i].to][z[k][j].to];
            }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j) continue;
                if(lx[i][j]!=err){
                    dt[i].push_back({(ll)j,lx[i][j]});

                }
        }
    for(int i=1;i<=n;i++) dij(i);
//------------------------------------//

    for(int k=1;k<=q;k++){
        cin>>x>>y;
        ll minn=1e18;
        for(int i=0;i<z[x].size();i++)
            for(int j=0;j<z[y].size();j++){
                minn=min(z[x][i].t + z[y][j].t + dis[z[x][i].to][z[y][j].to] + wk[x] + wk[y],minn);
            }
        cout<<minn<<'\n';
    }
	return 0;
}
