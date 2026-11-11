#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
long long c,n,m,d,q;
long long w[500005];
vector<long long> a[501];
vector<long long> t[501];
vector<long long> ord[500001];
long long dijkstra(long long s,long long tt){
	long long dist[500005];
	bool vis[500005];
	for(int i=1;i<=m;i++) dist[i]=INF;
	
	dist[s]=0;
	for(int _=1;_<=m;_++){
		long long u=0;
		long long mi=INF;
		for(int j=1;j<=m;j++) if(dist[j]<=mi&&!vis[j]) mi=dist[j],u=j;
		vis[u]=1;
		for(int i=0;i<ord[u].size();i++){
			for(int j=0;j<a[ord[u][i]].size();j++){
				if(a[ord[u][i]][j]==u) continue;
				else dist[a[ord[u][i]][j]]=min(dist[a[ord[u][i]][j]],dist[u] + t[ord[u][i]][u] + t[ord[u][i]][a[ord[u][i]][j]]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<dist[i]<<' '<<vis[i]<<endl;
//	}
//	cout<<"------------------------------------------\n";
	return w[s]+dist[tt]+w[tt];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	a.resize(n+1);
//	t.resize(n+1);
//	ord.resize(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			ord[aa].push_back(i);
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<ord[i].size();j++){
//			cout<<ord[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<"------------------------------------------\n";
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)<<endl;
	}
}
