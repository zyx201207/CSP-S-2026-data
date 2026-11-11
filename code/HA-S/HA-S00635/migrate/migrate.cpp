#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct NODE {
	int id;
	int step;
};

struct node {
	int cnt;
	int mindist;
};

int t;
int n,d;
int x[5005];
node dist[5005][5005];
bool vis[5005];
int ans;

void dfs(int u,int step) {
	for(int v=1;v<=n;v++){
		if(vis[v]==1&&abs(x[v]-x[u])<=d){
			if(dist[u][v].mindist>step){
				dist[u][v].mindist=step;
				dist[u][v].cnt=1;
				dfs(u,step+1);
			}
		}
		if(vis[v]!=1&&abs(x[v]-x[u])<=d){
			dist[u][v].cnt++;
			dist[u][v].mindist=step;
			vis[v]=1;
			dfs(u,step+1);
			vis[v]=0;
		}
	}
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t>>t;
	while(t--) {
		cin>>n>>d;
		memset(x,0,sizeof(x));
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		for(int i=1; i<=n; i++) {
			dist[i][i].cnt=1;
			dist[i][i].mindist=0;
		}

		for(int i=1; i<=n; i++) {
			vis[i]=1;
			dfs(i,0);
			vis[i]=0;
		}

		for(int u=1; u<=n; u++) {
			for(int v=1; v<=n; v++) {
				if(dist[u][v].cnt==2) {
					ans++;
				}
			}
		}

		cout<<ans<<"\n";
	}

	return 0;
}
