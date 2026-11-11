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

void bfs(int u) {
	queue <NODE> q;

	q.push({1,0});
	vis[1]=1;
	while(!q.empty()) {
		int t=q.front().id;
		int step=q.front().step;
		q.pop();

		for(int v=1; v<=n; v++) {
			if(vis[v]==1&&step==dist[u][v].mindist) {
				dist[u][v].cnt++;
			}
			if(vis[v]!=1&&abs(x[v]-x[t])<=d) {
				q.push({v,step+1});
				dist[u][v].cnt++;
				dist[u][v].mindist=step;
			}
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			bfs(i);
		}

		for(int u=1; u<=n; u++) {
			for(int v=1; v<=n; v++) {
				if(dist[u][v].cnt==2){
					ans++;
				}
			}
		}

		cout<<ans<<"\n";
	}

	return 0;
}
