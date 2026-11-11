#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
const int M=5e5+5,N=505;
const long long inf=1e18;
int ID,n,m,D,Q,a[M],ct[M];
long long f[N][N];
pi e[M][21];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ID>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k,x,y;
		cin>>k;
		while(k--){
			cin>>x>>y;
			e[x][++ct[x]]={i,y};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=inf;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=ct[i];j++)
			for(int k=j+1;k<=ct[i];k++)f[e[i][j].first][e[i][k].first]=f[e[i][k].first][e[i][j].first]=min(f[e[i][j].first][e[i][k].first],1ll*e[i][j].second+e[i][k].second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(Q--){
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for(int i=1;i<=ct[x];i++)
			for(int j=1;j<=ct[y];j++)ans=min(ans,f[e[x][i].first][e[y][j].first]+e[x][i].second+e[y][j].second);
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}