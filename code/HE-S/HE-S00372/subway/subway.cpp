#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
const int INF=1e18+5;
vector<pair<int,int> > g[N];
int dis[N][N];
void dijk(int n,int s){
	fill(dis[s]+1,dis[s]+1+n,INF);
	dis[s][s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	pair<int,int> p;
	p.first=0;p.second=s;
	q.push(p);
	while(!q.empty()){
		pair<int,int> nw=q.top();q.pop();
		int u=nw.second;
		int d=nw.first;
		if(dis[s][u]<d) continue;
		for(int i=0;i<g[u].size();++i){
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				pair<int,int> p;
	            p.first=dis[s][v];p.second=v;
				q.push(p);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=0;i<n;++i){
		int k;cin>>k;
		int a,t,a1,t1;
		cin>>a>>t>>a1>>t1;
		pair<int,int> p;
	    p.first=a1;p.second=t+t1;
	    pair<int,int> p1;
	    p1.first=a;p1.second=t+t1;
		g[a].push_back(p);
		g[a1].push_back(p1);
	}
	for(int i=0;i<q;++i){
		int x,y;cin>>x>>y;
		dijk(m,x);
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
