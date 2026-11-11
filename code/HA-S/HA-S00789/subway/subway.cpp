#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=600010;
int c,n,m,d,q,p,w[M];
ll dis[M],a[1010][1010],b[N][N];
vector<int>v[M];
bool mk[M];
int head[M],tot;
struct edge {
	int v,w,nxt;
}e[M*2];
void add (int u,int v,int w) {
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}
struct node {
    int id;
	ll dis;
	bool operator<(const node&o) const{
		return o.dis<dis;
	}
};
void dijkstra (int s) {
	for (int i=1;i<=n+m;i++) dis[i]=1e18,mk[i]=0;
	priority_queue<node>q;
	dis[s]=0;
	q.push({s,0});
	while (!q.empty()) {
		int u=q.top().id;
		q.pop();
		if (mk[u]) continue;
		mk[u]=1;
		for (int i=head[u];i;i=e[i].nxt) {
			int v=e[i].v,w=e[i].w;
			if (dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) {
		cin >> w[i];
	}
	for (int i=1;i<=n;i++) {
		int k;
		cin >> k;
		for (int j=1;j<=k;j++) {
			int x,y;
			cin >> x >> y;
			p=y;
			if (m<=1000) add(i+m,x,y);
			if (m<=1000) add(x,i+m,y);
			v[x].push_back(i);
		}
	}
	if (m<=1000) {
		for (int i=1;i<=m;i++) {
			dijkstra(i);
			for (int j=1;j<=m;j++) a[i][j]=dis[j];
		}
	}else{
		memset(b,0x3f,sizeof(b));
		for (int i=1;i<=n;i++) b[i][i]=0;
		for (int i=1;i<=m;i++) {
			for (int j=0;j<v[i].size();j++) {
				for (int k=0;k<v[i].size();k++) {
					if (j!=k) b[v[i][j]][v[i][k]]=1;
				}
			}
		}
		for (int k=1;k<=n;k++) {
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++) {
					b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
				}
			}
		}
	}
	while (q--) {
		int s,t;
		cin >> s >> t;
		if (m<=1000) cout << a[s][t]+w[s]+w[t] <<"\n";
		else {
			ll res=1e18;
			for (int i=0;i<v[s].size();i++) {
				for (int j=0;j<v[t].size();j++) {
				    res=min(res,b[v[s][i]][v[t][j]]);
				}
			}
			cout << res*2*p+2*p+w[s]+w[t] <<"\n";
		}
	}
	return 0;
}
