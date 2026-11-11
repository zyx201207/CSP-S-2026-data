#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,D=30,inf=0x3f3f3f3f3f3f3f3f;
int cas,n,m,d,Q,ans;
int w[M],f[N][N];
int k[N];
//int a[N][D],t[N][D];
int to[M][D],cnt[M],tt[M][D];
struct node{
	int col,t;
};
vector<node>e[M];
signed main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>cas>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aa,t;
			cin>>aa>>t;
			cnt[aa]++;
			to[aa][cnt[aa]]=i;
			tt[aa][cnt[aa]]=t;
			e[aa].push_back({i,t});
		}
	}
	memset(f,inf,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int x=0;x<e[i].size();x++){
			for(int y=x+1;y<e[i].size();y++){
				int u=e[i][x].col,v=e[i][y].col;
				int tim=e[i][x].t+e[i][y].t;
				f[u][v]=f[v][u]=min(f[u][v],tim);
			}
		}
	}
//	cout<<f[1][2]<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int x=j+1;x<=n;x++){
				f[j][x]=f[x][j]=min(f[j][x],f[i][j]+f[i][x]);
			}
		}
	}
	while(Q--){
		int u,v;cin>>u>>v;
		if(u==v){
			cout<<"0\n";
			continue;
		}
		ans=inf;
		for(int i=1;i<=cnt[u];i++){
			for(int j=1;j<=cnt[v];j++){
				int x=to[u][i],y=to[v][j];
				ans=min(ans,f[x][y]+tt[u][i]+tt[v][j]);
			}
		}
//		cout<<ans<<"\n";
		cout<<ans+w[u]+w[v]<<"\n";
	}

	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
