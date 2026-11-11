#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int INF=INT_MAX;
int a[N],dis[N][N];
int c,n,m,d,t;
struct node{
	int l[N]={},t[N]={},cnt;
}q[N],g[N];
void Dijkstra(int st){
	for(int i=1;i<=n;i++) dis[st][i]=INF;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >qu;
	dis[st][st]=0;
	qu.push({0,st});
	while(!qu.empty()) {
		auto f=qu.top();qu.pop();
		if(f.first>=dis[st][f.second]) continue;
		for(int i=1;i<=g[f.second].cnt;i++) {
			int u=g[f.second].l[i];
			int ut=g[f.second].t[i];
			for(int j=1;j<=q[u].cnt;j++) {
				int v=q[u].l[j];
				int vt=q[u].t[j];
				if(dis[st][f.second]+vt+ut<=dis[st][v]) {
					dis[st][f.second]=dis[st][u]+vt+ut;
					qu.push({dis[st][f.second],v});
				}
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			int l,ti;
			cin>>l>>ti;
			q[i].cnt++;
			q[i].l[q[i].cnt]=l;
			q[i].t[q[i].cnt]=ti;
			g[l].cnt++;
			g[l].l[g[l].cnt]=i;
			g[l].t[g[l].cnt]=ti;
		}
	}
	while(t--) {
		int st,ed,ans=0;
		cin>>st>>ed;
		Dijkstra(st);
		cout<<ans<<"\n";
	}
	return 0;
}
