#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100005;
struct Node{
	ll v , w;
	bool operator<(const Node& p) const{
		return w < p.w;
	}
};
struct Node1{
	ll u , v , id , ans;
}qu[N];
bool cmp1(Node1 x , Node1 y){
	return x.u < y.u;
}
bool cmp2(Node1 x , Node1 y){
	return x.id < y.id;
}
vector<Node> G[N];
ll d, c , n , m , q , w[N],cnt[N],vis[N*21] , dis[N * 21],mm;
void dij(int s){
	priority_queue<Node> q;
	for(int i = 1 ; i <= mm ; i++){
		vis[i] = false;
		dis[i] = 1e15+1;
	}
	q.push({s , 0}) ;
	dis[s] = 0;
	while(!q.empty()){
		Node pp = q.top();
		int u = pp.v;
		int w = pp.w;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto pp1 : G[u]){
			int v = pp1.v;
			int w1 = pp1.w;
			if(dis[u] + w1 < dis[v]){
				q.push({v , dis[u] + w1});
				dis[v] = dis[u] + w1;
			}			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1 ; i <= m ; i++){
		scanf("%lld",&w[i]);
		
	}
	for(int i = 1 ; i <= n ; i++){
		int tt;
		cin >> tt;
		int last = -1;
		for(int j = 1 ; j <= tt ; j++){
			int now , p;
			cin >> now >> p;
			cnt[now]++;
//			cout << now << " " << cnt[now]*m + now << endl;
			if(last != -1){
				G[last].push_back({cnt[now]*m + now,0});
				G[cnt[now]*m + now].push_back({last , 0});
			}
			last = cnt[now]*m + now;
			mm = max(mm , cnt[now]*m + now);
			G[now].push_back({cnt[now] * m + now , p});
			G[cnt[now] * m + now].push_back({now,p});
		}
	}
//	cout << endl << endl;
//	for(int i = 1 ; i <= m ; i++){
//		for(int j = 0 ; j <= cnt[i] ; j++){
//			cout << j * m + i << " ";
//			for(auto v : G[j * m + i]){
//				cout << v.v << " ";
//			}
//			cout << endl << endl;
//		}
//	}
	for(int i = 1 ; i <= q ; i++){
		scanf("%lld%lld",&qu[i].u,&qu[i].v);
		if(qu[i].u > qu[i].v){
			swap(qu[i].u , qu[i].v);
		}
		qu[i].id = i;
	}
	sort(qu + 1 , qu + q + 1 , cmp1);
	int lst = -1;
	for(int i = 1 ; i <= q ; i++){
		if(qu[i].u != lst){
			dij(qu[i].u);
		}
		qu[i].ans = dis[qu[i].v] + w[qu[i].u] + w[qu[i].v];
	}
	sort(qu + 1 , qu + q + 1 ,cmp2);
	for(int i = 1 ; i <= q ; i++){
		cout << qu[i].ans << endl;
	}
} /*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6*/
