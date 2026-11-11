#include<bits/stdc++.h>
using namespace std;
int n,m,T,c,d,q;
bool flag=0;
const int N=5e5+1;
long long w[N],k[N];
struct pos{
	int to;
	long long v;
};
vector<pos> a[N];
vector<pos> g[N];
bool vis[501];
long long f[501][501];
void dfs(int x){
	vis[x]=1;
	for(pos i:a[x]){
		for(pos j:g[i.to]){
			if(x!=j.to){
				int xx=min(x,j.to),yy=max(x,j.to);
				f[xx][yy]=min(f[xx][yy],j.v+i.v);
				if(!vis[j.to])
				dfs(j.to);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			f[i][j]=1e9;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,o,p;j<=k[i];j++){
			cin>>p>>o;
			a[i].push_back({p,o});
			g[p].push_back({i,o});
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[j][i]=f[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		long long ans=LONG_LONG_MAX;
		int x,y;
		cin>>x>>y;
		for(pos i:g[x]){
			for(pos j:g[y]){
				ans=min(ans,f[i.to][j.to]+i.v+j.v);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
} 
