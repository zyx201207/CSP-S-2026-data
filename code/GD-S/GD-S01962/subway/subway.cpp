#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int res = 0;char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch))res = res * 10 - '0' + ch,ch = getchar();
	return res;
}
const int N = 520,M = 5e5 + 10,inf = 1e18;
int c,n,m,d,q,w[M],dis[N];
struct node{
	int l,val;
	inline friend bool operator < (node a,node b){
		return a.val > b.val;
	}
};
vector<node > ln[M],G[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i <= m;i++) w[i] = read();
	for(int i = 1,siz;i <= n;i++){
		siz = read();
		for(int j = 1;j <= siz;j++)ln[read()].push_back({i,read()});
	}
	for(int i = 1;i <= m;i++){
		for(auto k : ln[i]){
			for(auto s : ln[i]){
				if(s.l != k.l){
					G[s.l].push_back({k.l,s.val + k.val});
				}
			}
		}
	}
	while(q--){
		int l = read() , r = read() , ans = inf;
		for(int i = 1;i <= n;i++)dis[i] = inf;
		priority_queue<node> pq;
		for(auto k : ln[l])dis[k.l] = k.val , pq.push(k);
		while(!pq.empty()){
			node t = pq.top() ; pq.pop();
			for(auto k : G[t.l]){
				if(t.val + k.val < dis[k.l]){
					dis[k.l] = t.val + k.val;
					pq.push({k.l,dis[k.l]});
				}
			}
		}
		for(auto k : ln[r])ans = min(ans,dis[k.l] + k.val);
		cout << ans + w[l] + w[r] << "\n";
	}
	return 0;
}
