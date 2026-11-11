#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int c,n,m,d,qu;
int ww[N],v[N],vis[N];
long long f[N];
int k,a,tt;
int tot=0;
vector<int>q[N],w[N];
vector<int>h[N],t[N];//表示每一个点的不同形态的编号 
void dij(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p;
	p.push({0,x});
	v[x]=1;f[x]=0;vis[1]=1;
	while(!p.empty()){
		int u=p.top().second;
		p.pop();v[u]=0;vis[u]=1;
		for(int i=0;i<q[u].size();i++){
			int ne=q[u][i],w_ne=w[u][i];
			if(vis[ne]==0){
				p.push({f[ne],ne});v[ne]=1;
			}
			if(f[u]+w_ne<f[ne]){
				f[ne]=f[u]+w_ne;
				if(v[ne]==0){
					p.push({f[ne],ne});v[ne]=1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qu);
	for(int i=1;i<=m;i++){
		scanf("%d",&ww[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&tt);
			t[a].push_back(tt);
			h[a].push_back(++tot);
			for(int k=0;k<h[a].size()-1;k++){
				int x=h[a][k],w_k=t[a][k];
				q[tot].push_back(x);
				w[tot].push_back(w_k+tt);
				w[x].push_back(w_k+tt);
				q[x].push_back(tot);
			}
			if(j>1){
				q[tot].push_back(tot-1);
				w[tot].push_back(0);
				q[tot-1].push_back(tot);
				w[tot-1].push_back(0);
			}
		}
	}
	while(qu--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<h[x].size();i++){
			for(int j=1;j<=tot;j++)
				f[j]=1e9,v[j]=0,vis[j]=0;
			dij(h[x][i]);
			for(int j=0;j<h[y].size();j++)
				ans=min(ans,f[h[y][j]]+t[y][j]+t[x][i]);
		}
		ans+=ww[x]+ww[y];
		printf("%d\n",ans);
	}
	return 0;
}
