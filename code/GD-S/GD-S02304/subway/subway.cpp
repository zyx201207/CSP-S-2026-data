#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const int N=505,M=5e5+5,D=22;
const ll inf=1e18;

int c,n,m,d,q,w[M];
int cnt[M],e[M][D],t[M][D];
ll dis[N][N];

void floyd(){
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
}

int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1,k;i<=n;i++){
		cin>>k;
		while (k--){
			int a,b;
			cin>>a>>b;
			cnt[a]++,e[a][cnt[a]]=i,t[a][cnt[a]]=b;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i^j) dis[i][j]=inf;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=cnt[i];j++)
			for (int k=1;k<=cnt[i];k++)
				dis[e[i][j]][e[i][k]]=min(dis[e[i][j]][e[i][k]],0ll+t[i][j]+t[i][k]);
	floyd();
	while (q--){
		int x,y;
		ll ans=inf;
		cin>>x>>y;
		for (int i=1;i<=cnt[x];i++)
			for (int j=1;j<=cnt[y];j++)
				ans=min(ans,t[x][i]+t[y][j]+dis[e[x][i]][e[y][j]]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
