#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int to[M],nx[M],head[M],zzz,n,m,kkk,t,cnt,vis1[21000],vis[2010];
long long w[M],d[2010][2510],c[M],dd[21000];
void add(int u,int v,long long money) {
	to[++cnt]=v;
	w[cnt]=money;
	nx[cnt]=head[u];
	head[u]=cnt;
}
void dij(int x) {
	for(int i=1; i<=n+m; i++) {
		d[x][i]=1e18;
	}
	memset(vis,0,sizeof(vis));
	priority_queue<pair<long long,int> >q;
	d[x][x]=0;
	q.push(make_pair(0,x));
	while(!q.empty()) {
		int now=q.top().second;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=head[now]; i; i=nx[i]) {
			int id=to[i];
			if(d[x][id]>d[x][now]+w[i]) {
				d[x][id]=d[x][now]+w[i];
				q.push(make_pair(-d[x][id],id));
			}
		}
	}
}
void dij1(int x) {
	for(int i=1; i<=n+m; i++) { 
		dd[i]=1e18;
	}
	memset(vis1,0,sizeof(vis1));
	priority_queue<pair<long long,int> >q;
	dd[x]=0;
	q.push(make_pair(0,x));
	while(!q.empty()) {
		int now=q.top().second;
		q.pop();
		if(vis1[now])continue;
		vis1[now]=1;
		for(int i=head[now]; i; i=nx[i]) {
			int id=to[i];
			if(dd[id]>dd[now]+w[i]) {
				dd[id]=dd[now]+w[i];
				q.push(make_pair(-dd[id],id));
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>zzz>>n>>m>>kkk>>t;
	for(int i=1; i<=m; i++) {
		cin>>c[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int x,y;
			cin>>x>>y;
			add(x,i+m,y);
			add(i+m,x,y);
		}
	}
	if(zzz<=15&&zzz>=12) {
		while(t--) {
			int x,y;
			cin>>x>>y;
			dij1(x);
			cout<<c[x]+c[y]+dd[y]<<"\n";
		}
		return 0;
	}
	for(int i=1; i<=m; i++) {
		dij(i);
	}
	while(t--) {
		int x,y;
		cin>>x>>y;
		cout<<c[x]+c[y]+d[x][y]<<"\n";
	}
	return 0;
}
