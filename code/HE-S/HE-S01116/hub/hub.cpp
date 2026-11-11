#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch-'0'); ch=getchar();}
	return x * f;
}
inline void write(int x) {
	if(x < 0) putchar('-'), x=-x;
	if(x > 9) write(x/10); putchar(x%10+'0');
}
inline void wt(int x,char ch) {
	write(x); putchar(ch);
}
int n, k;
const int N = 1e6+7;
vector <int> e[N];
int fa[N], sz[N], has[N];
int vis[N], dis[N];
int tot;
int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}  
void merge(int x,int y) {
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	if(has[x] && has[y]) tot--;
	if(sz[fx] > sz[fy]) swap(fx,fy);
	fa[fx] = fy;
	sz[fy] += sz[fx];
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c = rd(), t = rd();
	while(t--) {
		int n = rd(), k = rd();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++) {
			int u = rd(), v = rd();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		queue <int> q; 
		int ans = 1e9;
		for(int i=0;i<(1<<n);i++) {
			int cnt = 0;
			for(int bt=0;bt<n;bt++) {
				if((i >> bt) & 1) cnt++; 
			}
			if(cnt != k) continue;
			for(int j=1;j<=n;j++) fa[j] = j, sz[j] = 1, vis[j] = 0;
			for(int bt=0;bt<n;bt++) 
				if((i >> bt) & 1) has[bt+1] = 1;
				else has[bt+1] = 0;
			tot = k;
			for(int bt=0;bt<n;bt++) {
				int id = bt+1;
				if((i >> bt) & 1) {
					for(auto v : e[id]) {
						merge(v,id); 
					}
				}
			}
			if(tot > 2) continue;
			for(int bt=0;bt<n;bt++) {
				int id = bt+1;
				if((i >> bt) & 1) {
					q.push(id);
					vis[id] = 1;
					dis[id] = 0;
				}
			}
			while(!q.empty()) {
				int u = q.front(); q.pop();
				for(auto v : e[u]) {
					if(vis[v]) continue;
					dis[v] = dis[u] + 1;
					vis[v] = 1;
					q.push(v);
				} 
			}		
			int res = 0;
			for(int i=1;i<=n;i++) res = max(res,dis[i]);
			ans = min(ans,res);
		}
		wt(ans,'\n');
	} 
	return 0;
}
