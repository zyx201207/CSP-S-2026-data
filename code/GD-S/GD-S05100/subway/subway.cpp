#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,r;
	cin>>c>>m>>n>>d>>r;
	int siz=n+m;
	vector<vector<int>> dis(siz+1,vector<int>(siz+1,1e9));//给每个线路建一个虚点 
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			int t;
			cin>>t;
			dis[x][n+i]=t;//线路经过的站点连到虚点上 
			dis[n+i][x]=t;
		}
	}
	//Floyd
	for(int i=1;i<=siz;i++){
		dis[i][i]=0;
	}
	for(int k=1;k<=siz;k++){
		for(int i=1;i<=siz;i++){
			for(int j=1;j<=siz;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(r--){
		int u,v;
		cin>>u>>v;
		cout<<a[u]+a[v]+dis[u][v]<<'\n';
	}
} 
