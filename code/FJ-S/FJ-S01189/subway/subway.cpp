#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;
int read() {
	char ch=getchar();
	int flag=1,res=0;
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')flag=-1,ch=getchar();
	while(ch>='0'&&ch<='9')res*=10,res+=(ch-'0'),ch=getchar();
	return res*flag;
}
int c,n,m,d,q;
int diss[550][550];
int dd[505050];
int k[505050];
vector<pair<int,int> > gg[505050];
vector<pair<int,int> > g[550];

void Dijkstra(int s) {
	priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int> >> q;
	q.push({0,s});
	vector<int> dis(550,inf);
	vector<int> vis(550,0);
	dis[s]=0;
	while(!q.empty()) {
		int now=q.top().second,val=q.top().first;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(auto x:g[now]) {
			int v=x.first,w=x.second;
			if(dis[v]>dis[now]+w) {
				dis[v]=dis[now]+w;
				q.push({val+w,v});
			}
		}
	}
	for(int i=1; i<=n; i++) {
		diss[s][i]=dis[i];
//		cout<<dis[i]<<" ";
	}
//	for(int i=1001;i<=1000+m;i++){
//		cout<<dis[i]<<" ";
//	}
//	cout<<"\n";
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//n=subways count,m=nodes count,q=questions count | total edges count<=5e5
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1; i<=m; i++) {
		dd[i]=read();
	}
	for(int i=1; i<=n; i++) {
		int k=read();
		int a,t;
		for(int j=1; j<=k; j++) {
			a=read(),t=read();
			gg[i].push_back({a+n+1,t});
			gg[a+n+1].push_back({i,t});
		}
	}
	for(int i=n+2; i<=n+2+m; i++) {
		if(gg[i].size()>=2) {
			for(int j=0; j<gg[i].size(); j++) {
				for(int k=0; k<gg[i].size(); k++) {
					if(j!=k) {
						int u,v,w;
						u=gg[i][j].first,v=gg[i][k].first;
						w=gg[i][j].second+gg[i][k].second;
						g[u].push_back({v,w});
						g[v].push_back({u,w});
//						cout<<u<<" "<<v<<" "<<w<<"\n";
					}
				}
			}
		}
	}
//	double st=clock();
	for(int i=1; i<=n; i++) {
		Dijkstra(i);
	}
//	double ed=clock();
//	cerr<<ed-st<<"\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<diss[i][j]<<"\n";
//		}
//	}
	while(q--) {
		int s=read(),t=read();
		int ans=inf;
		for(auto x:gg[s+n+1]) {
			int u=x.first,w1=x.second;
			for(auto y:gg[t+n+1]) {
				int v=y.first,w2=y.second;
				ans=min(ans,diss[u][v]+dd[s]+dd[t]+w1+w2);
			}
		}
		cout<<ans<<"\n";
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
*/
