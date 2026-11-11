#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long w[500005],K[505],f[505][505],g[505][505];
struct node{
	int v;
	long long w;
}; 
vector<node> h[500005];
int n,m,c,d,q;
signed main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		cin>>K[i];
		for(int j=1;j<=K[i];j++){
			long long aa,tt;
			cin>>aa>>tt;
			h[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=m;i++){
		int len=h[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				g[h[i][k].v][h[i][j].v]=g[h[i][j].v][h[i][k].v]=min(g[h[i][j].v][h[i][k].v],h[i][j].w+h[i][k].w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=g[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(f[i][j]>f[i][k]+f[j][k]){
					f[i][j]=f[i][k]+f[j][k];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		int lenx=h[x].size(),leny=h[y].size();
		for(int j=0;j<lenx;j++){
			for(int k=0;k<leny;k++){
				ans=min(ans,h[x][j].w+h[y][k].w+f[h[x][j].v][h[y][k].v]);
			}
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
//复杂度分析：输入m+sum(k)，建图md^2，floyd n^3，query qd^2，可以通过所有数据 
