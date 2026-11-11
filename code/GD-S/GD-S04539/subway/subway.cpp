#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long c,n,m,d,q,w[N],dis[N+507];
bool Vis[N+507];
struct node{
	long long to,cost;
	bool operator<(const node &other) const {
		return other.cost<cost;
	}
};
vector<node> road[N+507];
priority_queue<node> pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,p;i<=n;i++) {
		cin>>p;
		for(int j=1,a,b;j<=p;j++) {
			cin>>a>>b;
			road[m+i].push_back({a,b});
			road[a].push_back({m+i,b});
		}
	}
	for(int k=1,a,b;k<=q;k++) {
		cin>>a>>b;
		while(!pq.empty()) pq.pop();
		for(int j=1;j<=n+m;j++) Vis[j]=false,dis[j]=0x3fffffff;
		dis[a]=0;
		pq.push({a,0});
		while(!pq.empty()) {
			int to=pq.top().to,cost=pq.top().cost;
			pq.pop();
			if(Vis[to]) continue;
			Vis[to]=true;
			for(node i:road[to]) {
				if(dis[i.to]>i.cost+cost) {
					dis[i.to]=i.cost+cost;
					pq.push({i.to,dis[i.to]});
				}
			}
		}
		cout<<dis[b]+w[a]+w[b]<<endl;
	}
	return 0;
}
