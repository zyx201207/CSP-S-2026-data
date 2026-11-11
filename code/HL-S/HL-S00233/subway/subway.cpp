#include<bits/stdc++.h>
using namespace std;
int w[500001];
long long f[501][501];
struct edge{
	int v,w,to;
}e[500001];
int head[500001],cnt=0;
inline void add(int u,int v,int w){
	e[++cnt].v=v,e[cnt].w=w;
	e[cnt].to=head[u],head[u]=cnt;
}
//vector<pair<int,int>>e[500001];//line hctime
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1,y,z;j<=x;j++){
			cin>>y>>z;
			//e[y].emplace_back(i,z);
			add(y,i,z);
		}
		//cout<<i<<" is ok\n";
	}
	for(int i=1;i<=m;i++){
//		for(int j=0;j<e[i].size();j++){
//			int u=e[i][j].first,w1=e[i][j].second;
//			for(int k=0;k<e[i].size();k++){
//				int v=e[i][k].first,w2=e[i][k].second;
//				if(j!=k&&w1+w2<f[u][v]){
//					f[v][u]=f[u][v]=w1+w2; 
//				}
//			}
//		}
		//cout<<i<<" is doing\n";
		for(int x=head[i];x;x=e[x].to){
			for(int y=head[i];y;y=e[y].to){
				if(x!=y&&0ll+e[x].w+e[y].w<f[e[x].v][e[y].v]){
					f[e[x].v][e[y].v]=f[e[y].v][e[x].v]=0ll+e[x].w+e[y].w;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		long long ans=LONG_LONG_MAX;
//		for(auto u:e[x]){
//			for(auto v:e[y]){
//				ans=min(ans,f[u.first][v.first]+u.second+v.second+w[x]+w[y]);
//			}
//		}
		for(int u=head[x];u;u=e[u].to){
			for(int v=head[y];v;v=e[v].to){
				ans=min(ans,f[e[u].v][e[v].v]+e[u].w+e[v].w);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//B is in the C 
//16:03 AC


