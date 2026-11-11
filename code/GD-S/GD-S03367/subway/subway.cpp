#include<iostream>
using namespace std;
constexpr long long inf=1e18;
int c,n,m,d,q,x,y,a,k;
long long w[500003],t;
long long g[503][503];
int e[500003][23],top[500003];
long long l[500003][23];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			e[a][++top[a]]=i;
			l[a][top[a]]=t;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++)g[i][j]=g[j][i]=inf;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<top[i];j++){
			for(int o=j+1;o<=top[i];o++){
				g[e[i][j]][e[i][o]]=g[e[i][o]][e[i][j]]=min(g[e[i][o]][e[i][j]],l[i][j]+l[i][o]);
			}
		}
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				g[i][j]=g[j][i]=min(g[i][o]+g[o][j],g[i][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		long long ans=inf;
		for(int i=1;i<=top[x];i++){
			for(int j=1;j<=top[y];j++)ans=min(ans,l[x][i]+l[y][j]+g[e[x][i]][e[y][j]]);
		}
		cout<<w[x]+ans+w[y]<<'\n';
	}
	return 0;
}
