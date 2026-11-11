#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,mod=1e9+7;
const long long inf=6e18;
int C,n,m,d,q;
int c[N];
int k[N];
int a[25][N],tot[N];
long long e[505][505],b[25][N];
void solve(){
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long x,t;
			cin>>x>>t;
			a[++tot[x]][x]=i;
			b[tot[x]][x]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=inf;
		} 
	}
	for(int i=1;i<=n;i++){
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int o=j+1;o<=tot[i];o++){
				e[a[j][i]][a[o][i]]=min(e[a[j][i]][a[o][i]],1ll*b[j][i]+b[o][i]);
				e[a[o][i]][a[j][i]]=min(e[a[o][i]][a[j][i]],1ll*b[o][i]+b[j][i]);
//				cout<<e[a[j][i]][a[o][i]]<<" ";
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(e[i][k]==inf)continue;
			for(int j=1;j<=n;j++){
				if(e[k][j]==inf)continue;
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	for(int _=1;_<=q;_++){
		int u,v;
		cin>>u>>v;
		long long ans=6e18;
		for(int i=1;i<=tot[u];i++){
			for(int j=1;j<=tot[v];j++){
				if(e[a[i][u]][a[j][v]]==inf)continue;
				ans=min(ans,1ll*b[i][u]+b[j][v]+e[a[i][u]][a[j][v]]);
			}
		}
//		cout<<e[a[1][u]][a[1][v]]<<" ";
//		cout<<c[u]<<" "<<ans<<" "<<c[v]<<"\n";
		cout<<c[u]+c[v]+ans<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	} 
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
