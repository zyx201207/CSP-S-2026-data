#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 503, M = 505+1;
int c,n,m,d,q;
ll T[N][M];
ll w[M];
vector<int> line[N];
vector<int> sta[M];
struct road{
	int to;
	ll w;
	bool operator < (const road& a) const {
		return a.w<w;
	}
};
vector<road> g[N];
int x,y;
ll ans;
ll dj[N];
bool vis[N];
priority_queue<road> pq;
void Dij(){
	ans=INT_MAX;
	for(int i=0; i<=n; i++){
		dj[i]=INT_MAX;
		vis[i]=false;
	}
	for(auto e:sta[y]){
//		cout<<y<<' '<<e<<endl;
		for(auto s:sta[x]){
			dj[s]=0;
			pq.push({s,T[s][x]});
		}
		while(!pq.empty()){
			int to=pq.top().to, w=pq.top().w;
			pq.pop();
			if(vis[to])	continue;
			vis[to]=false;
			for(auto i:g[to]){
				if(dj[i.to]>dj[to]+i.w){
					dj[i.to]=dj[to]+i.w;
					pq.push({i.to,dj[i.to]});
				}
			}
		}
//		cout<<e<<' '<<dj[e]<<endl;
		if(ans>dj[e]+T[e][y]){
			ans=dj[e]+T[e][y];
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1; i<=m; i++){
		scanf("%lld", &w[i]);
	}
	int k,a,t;
	for(int i=1; i<=n; i++){
		scanf("%d", &k);
		for(int j=1; j<=k; j++){
			scanf("%d%d", &a, &t);
			T[i][a]=t;
			line[i].push_back(a);
			sta[a].push_back(i);
		}
	}
	for(int i=1; i<=n; i++){
		for(auto j:line[i]){
			for(auto k:sta[j]){
				if(k!=i){
					g[i].push_back({k,T[i][j]+T[k][j]});
				}
			}
		}
	}
	for(int i=0; i<q; i++){
		scanf("%d%d", &x, &y);
		Dij();
		printf("%lld\n", ans+T[1][x]+w[x]+w[y]);
		
	}
	return 0;
}
