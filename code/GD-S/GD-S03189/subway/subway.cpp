#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int st,ed;
ll w[500005];
vector<int> blg[500005];
vector<int> k[505];//第i个路线的成员 
int g[1005][1005];
vector<int> eg[500005];
ll ans=0;
int mb;
int t[50005][505];//第i个地铁站厅到j线路的时间
bool check(int u,int v,int nowlu){
	for(int i=0;i<blg[v].size();i++){
		int lu1=blg[v][i];
		for(int j=0;j<k[lu1].size();j++){
			int mu=k[lu1][j];
			if(mu==u){
				if(lu1!=nowlu){
					mb=lu1;
				}
				else{
					return 1;
				}
			}
		}
	}
	return 0;
} 
int vis[1005][1005];
void dfs(int u,ll num,int fa,int nowlu){
	if(u==ed){
		num+=t[u][nowlu];
		ans=min(ans,num);
		return ;
	}
	for(int i=0;i<eg[u].size();i++){
		int v=eg[u][i];
		if(vis[u][v]) continue;
		if(v==fa) continue;
		vis[u][v]=vis[v][u]=1;
		if(check(u,v,nowlu)){
			dfs(v,num,u,nowlu);
		}
		else{
			dfs(v,num+t[u][nowlu]+t[u][mb],u,mb);
		}
		vis[u][v]=vis[v][u]=0;
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int len;
		scanf("%d",&len);
		vector<int> p;
		for(int j=1;j<=len;j++){
			int po,ti;
			scanf("%d%d",&po,&ti);
			blg[po].push_back(i);
			p.push_back(po);
			t[po][i]=ti;
			k[i].push_back(po);
		}
		for(int j=1;j<p.size();j++){
			g[p[j]][p[j-1]]=1;
			g[p[j-1]][p[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(i==j) continue;
			if(g[i][j]){
				eg[i].push_back(j);
				eg[j].push_back(i);
			}
		}
	}
	while(q--){
		scanf("%d%d",&st,&ed);
		ans=1e15;
		for(int i=0;i<blg[st].size();i++){
			int lu=blg[st][i];
			ll num=t[st][lu];
			dfs(st,num,st,lu);
		}
		printf("%lld\n",1LL*(w[st]+w[ed]+ans));
	}
	return 0;
} 
