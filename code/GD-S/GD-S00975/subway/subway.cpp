#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
#define REP(i,x,y,z) for(int i=x;i>=y;i-=z)
#define PII pair<int,int>
void rd(int &x){
	int f=1;x=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+(c-'0'),c=getchar();
	x*=f;
}const int N=5e2+10,M=5e5+10;
int n,m,d,q,f[N][N],w[M],deep[N][N],vis[N];
vector<PII>e[N],p[M];
void dij(int s){
	FOR(i,1,n,1)f[s][i]=1e16,vis[i]=false;
	priority_queue<PII,vector<PII>,greater<PII>>q;
	f[s][s]=0;q.push({0ll,s});while(!q.empty()){
		int z=q.top().first,u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=true;FOR(i,0,e[u].size()-1,1){
			int v=e[u][i].first,w=e[u][i].second,nz=f[s][u]+w;
			if(f[s][v]>nz){
				f[s][v]=nz;
				if(!vis[v])q.push({nz,v});
			}
		}
	}
}signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int C;rd(C),rd(n),rd(m),rd(d),rd(q);
	FOR(i,1,m,1)rd(w[i]);
	FOR(i,1,n,1){
		int k;rd(k);
		FOR(j,1,k,1){
			int a,t;
			rd(a),rd(t);
			p[a].push_back({i,t});
		}
	}FOR(i,1,n,1)FOR(j,1,n,1)deep[i][j]=1e16;
	FOR(u,1,m,1)FOR(i,0,p[u].size()-1,1)FOR(j,0,p[u].size()-1,1){
		if(i==j)continue;
		int x=p[u][i].first,t1=p[u][i].second,y=p[u][j].first,t2=p[u][j].second;
		deep[x][y]=deep[y][x]=min(deep[x][y],t1+t2); 
	}FOR(i,1,n,1)FOR(j,1,n,1){
		if(deep[i][j]>3e9)continue;
		e[i].push_back({j,deep[i][j]}),e[j].push_back({i,deep[i][j]});
	}FOR(i,1,n,1)dij(i);
	while(q--){
		int u,v,ans=1e12;rd(u),rd(v);
		FOR(i,0,p[u].size()-1,1)FOR(j,0,p[v].size()-1,1){
			int x=p[u][i].first,t1=p[u][i].second,y=p[v][j].first,t2=p[v][j].second;
			ans=min(ans,f[x][y]+w[u]+w[v]+t1+t2);
		}cout<<ans<<"\n";
	}return 0;
}
