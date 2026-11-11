#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005,D=25;
long long d[N][N],a[M][D],w[M];
int n,m,c,dd,q,cnt[M],id[M][D],k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x,u,v;
	memset(d,0x3f,sizeof(d));
	long long y;
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			cnt[x]++;
			id[x][cnt[x]]=i;
			a[x][cnt[x]]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				if(j!=k){
					u=id[i][j];
					v=id[i][k];
					y=a[i][j]+a[i][k];
					d[u][v]=d[v][u]=min(d[u][v],y);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		y=1e18;
		cin>>u>>v;
		for(int j=1;j<=cnt[u];j++){
			for(int k=1;k<=cnt[v];k++){
				y=min(y,d[id[u][j]][id[v][k]]+a[u][j]+a[v][k]);
			}
		}
		y+=w[u];
		y+=w[v];
		cout<<y<<'\n';
	}
	return 0;
}
