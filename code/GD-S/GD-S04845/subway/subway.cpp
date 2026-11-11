#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >e[500001];
int w[500001];
long long dis[502][502];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin >>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >>a>>t;
			e[a].push_back(make_pair(i,t));
		//	cout <<a<<' '<<i<<'\n';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=0x3f3f3f3f3f3f3f3fll;
		}
		dis[i][i]=0;
	}
	//复杂度o(d^2*m) 存在问题 右向右建边需要更优 
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)e[i].size();j++){
			for(int k=0;k<j;k++){
				int u=e[i][j].first;
				int v=e[i][k].first;
				long long w=e[i][j].second+e[i][k].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	// 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		long long ans=0x3f3f3f3f3f3f3f3fll;
		int x,y;
		cin >>x>>y;
		for(int i=0;i<(int)e[x].size();i++){
			for(int j=0;j<(int)e[y].size();j++){
				int u=e[x][i].first;
				int v=e[y][j].first;
				long long w=e[x][i].second+e[y][j].second;
				ans=min(w+dis[u][v],ans);
			}
		}
		cout <<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
