#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
struct node{
	int pos,dis;
	bool operator < (const node& x)const{
		return x.dis<dis;
	}
};
int c,n,m,d,q,w[510],k[N],a[N][510],t[N][510],dis[510];
bool vis[510],visl[N];
vector<ll> plat[510];
void dijstkra(int s){
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<node> pq;
	pq.push({s,0});
	while(!pq.empty()){
		auto p=pq.top();
		pq.pop();
		if(vis[p.pos]) continue;
		vis[p.pos]=1;
		for(auto l:plat[p.pos]){
			if(visl[l]) continue;
			for(int i=1; i<=k[l]; i++){
				if(dis[a[l][i]]>dis[p.pos]+t[l][p.pos]+t[l][i]){
					dis[a[l][i]]=dis[p.pos]+t[l][p.pos]+t[l][i];
					pq.push({a[l][i], dis[a[l][i]]});
				}
			}
			visl[l]=1;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++){
		cin >> k[i];
		for(int j=1; j<=k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			plat[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		dijstkra(x);
		cout << dis[y]+w[x]+w[y] << '\n';
	}
	return 0;
}
