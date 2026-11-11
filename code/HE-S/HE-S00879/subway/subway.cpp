#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
int c,n,m,d,q,tot,tot1;
int a[N],u[N],v[N],sta[N],siz[N],zh[N],siz1[N],num[N];
int w[510][N],inn[N][510],g[N][N];
bool f[510][N],f1[N];
inline ll dfs(int opt,int u,int v,ll ans,ll tot){
	if(u==v){
		return min(ans,tot);
	}
	tot+=w[opt][u];
	for(int i=1;i<=num[opt];i++){
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=d;i++){
		for(int j=1;j<=m;j++){
			w[d][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			int v,val;
			cin>>v>>val;
			w[i][v]=val;
			g[i][j]=v;
			f[i][v]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u[i]>>v[i];
		if(!f1[u[i]])f1[u[i]]=1,sta[++tot]=u[i];
		if(!f1[v[i]])f1[v[i]]=1,sta[++tot]=v[i];//zh[++tot1]=v[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=tot;i++){
			if(f[j][sta[i]]){
				inn[sta[i]][++siz[sta[i]]]=j;
			}		
		}
//		for(int i=1;i<=tot1;i++){
//			if(f[j][zh[i]]){
//				inn1[zh[i]][++siz1[zh[i]]]=j;
//			}
//		}
	}
	for(int i=1;i<=q;i++){ll  maxn=1e18;
		for(int j=1;j<=siz[u[i]];j++){
			
			maxn=min(maxn,(long long)dfs(inn[u[i]][j],u[i],v[i],1e18,0)+(long long)(a[v]+a[u]));
			
		}cout<<maxn<<'\n';		
	}
	return 0;
}

