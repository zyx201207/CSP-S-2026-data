#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505;
ll c,n, m,d, q, a[N], dis[N];
bool vis[N];
struct node{
	ll v, w;
	bool operator < (const node &rhs) const{
		return w>rhs.w;
	}
}now ;
vector<node> G[N];
void djs(int b, int e){
	priority_queue<node> pq;
	memset(dis,0x3f,sizeof dis);
	memset(vis, false, sizeof vis);
	dis[b]=0;
	pq.push(node{b, 0});
	while(!pq.empty()){
		now=pq.top();
		pq.pop();
		ll d=now.v;
		if(vis[d]) break;
		vis[d]=true;
		for(int i=0; i<G[d].size(); ++i){
			ll nxt=G[d][i].v, l=G[d][i].w;
			if(!vis[nxt]&&now.w+l < dis[nxt]){
				dis[nxt]=now.w+l;
				pq.push(node{nxt, dis[nxt]});
			}
		}
	}
//	return dis[e];
}

int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q; 
	for(int i=1; i<=m; ++i) cin >> a[i]; 
	for(int i=1; i<=n; ++i){
		ll k; cin >> k;
		ll z[1005], t[1005];
		for(int j=1; j<=k; ++j){
			cin >> z[j] >> t[j];
		}
		//建立图
		//如何：前一个+后一个：G[1][2]=t[1]+t[2]
		for(int j=1; j<=k; ++j){
			for(int l=j+1; l<=k; ++l){
			//为z[j]->z[l]建边（无向）
				if(j!=l){
					G[z[j]].push_back(node{z[l], t[j]+t[l]});
					G[z[l]].push_back(node{z[j], t[j]+t[l]});
				}
			}
		}

	}	
		
	//建立超级起点的优化没有写
	while(q--){
		int b, e;
		cin >> b >> e;
		
		djs(b,e);
		ll ans=dis[e]+a[b]+a[e];
		cout << ans << '\n';
	}
	return 0;
}
