#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int w[500001];
struct e{int a;long long t;};
vector<e>lx[500001];
long long dis[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	memset(dis,127/4,sizeof(dis));
	int c,n,m,d,q,x,y,a,k,i,j,l;
	long long t,ans;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;++i)
		cin>>w[i];
	for(i=1;i<=n;++i){
		cin>>k,dis[i][i]=0;
		for(j=1;j<=k;++j){
			cin>>a>>t;
			for(l=lx[a].size()-1;l>-1;--l)
				dis[lx[a][l].a][i]=dis[i][lx[a][l].a]=min(dis[i][lx[a][l].a],t+lx[a][l].t);
			lx[a].push_back({i,t});
		}
	}
	for(l=1;l<=n;++l)
		for(i=1;i<=n;++i)
			if(l!=i)
			for(j=n;j>i;--j)
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	while(q--){
		ans=1e18;
		cin>>x>>y;
		for(j=lx[x].size()-1,l=lx[y].size()-1;j>-1;--j)
			for(k=l;k>-1;--k)
				ans=min(ans,lx[x][j].t+lx[y][k].t+dis[lx[x][j].a][lx[y][k].a]);
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
