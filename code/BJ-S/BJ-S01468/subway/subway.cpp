#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q;
int ldis[514][514],w[5*114514];
struct edge{
	int v,w;
};
vector<edge> e[5*114514];
void addedge(int u,int v,int w){
	e[u].push_back((edge){v,w});
	e[v].push_back((edge){u,w});
	return ;
}
void floyd(){
	for(int u = 1;u<=n;u++){
		for(int v = 1;v<=u;v++){
			for(int p = 1;p <= u;p++){
				if(ldis[u][p] >= (int)1e18||ldis[p][v] >= (int)1e18)continue;
				ldis[u][v] = min(ldis[u][v],ldis[u][p]+ldis[p][v]);
				ldis[v][u] = min(ldis[v][u],ldis[v][p]+ldis[p][u]);
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ldis,0x7f,sizeof(ldis));
	cin>>C>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	int K,V,W;
	for(int i = 1;i<=n;i++){
		ldis[i][i] = 0;
		cin>>K;
		for(int j = 1;j<=K;j++){
			cin>>V>>W;
			addedge(m+i,V,W);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			ldis[i][j] /= 2;
			ldis[j][i] /= 2;
		}
	}
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<(int)e[i].size();j++){
			for(int k = j+1;k<(int)e[i].size();k++){
				ldis[e[i][j].v-m][e[i][k].v-m] = min(ldis[e[i][j].v-m][e[i][k].v-m],e[i][j].w+e[i][k].w);
				ldis[e[i][k].v-m][e[i][j].v-m] = min(ldis[e[i][k].v-m][e[i][j].v-m],e[i][j].w+e[i][k].w);
			}
		}
	}
	floyd();
	int U,ans;
	for(int i = 1;i<=q;i++){
		cin>>U>>V;
		ans = LONG_LONG_MAX/2;
		for(int j = 0;j<(int)e[U].size();j++){
			for(int k = 0;k<(int)e[V].size();k++){
				ans = min(ans,e[U][j].w+ldis[e[U][j].v-m][e[V][k].v-m]+e[V][k].w);
				//cout<<ldis[e[U][j].v-m][e[V][k].v-m]<<' '<<e[U][j].w<<' '<<e[V][k].w<<'\n';
			}
		}
		cout<<ans+w[U]+w[V]<<'\n';
	}
	return 0;
}
