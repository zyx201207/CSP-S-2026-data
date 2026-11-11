#include <bits/stdc++.h>//1-8
using namespace std;
const int N=1e5+5;
int c,m,n,d,q,cnt;
long long dis[N];
struct node{
	int v;
	long long w;
	bool operator <(const node& p)const{
		return w>p.w;
	}
};
priority_queue<node> pq;
vector<node> g[N];
bool vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		long long x;
		cin>>x;
		g[i].push_back({i+m,x}),g[i+m].push_back({i,x});
	}
	cnt=2*m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			long long x;
			cin>>a>>x;
			cnt++;
			g[cnt].push_back({a+m,x}),g[a+m].push_back({cnt,x});
			if(j!=1) g[cnt].push_back({cnt-1,0}),g[cnt-1].push_back({cnt,0});
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		
		while(pq.size()) pq.pop();
		
		pq.push({st,0});
		for(int i=1;i<=cnt;i++) vis[i]=false,dis[i]=1e18;
		dis[st]=0;
		
		while(pq.size()){
			node u=pq.top();
			pq.pop();
			if(vis[u.v]) continue;
			vis[u.v]=true;
			for(node i:g[u.v]){
				if(!vis[i.v]&&dis[i.v]>dis[u.v]+i.w){
					dis[i.v]=dis[u.v]+i.w;
					pq.push({i.v,dis[i.v]});
				}
			}
		}
		
		cout<<dis[ed]<<"\n";
	}
	return 0;
}
