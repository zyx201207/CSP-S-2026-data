#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int read(){
	int t = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return f * t;
}
int ICS, TCS;
int n, t;
const int N = 1e6 + 10;
vector<int>e[N];
namespace Sub1{
	int dep[N];
	int fa[N];
	int pre[N];
	void dfs(int now, int ff){
		fa[now] = ff;
		dep[now] = dep[ff] + 1;
		pre[now] = 0;
		for(auto y: e[now]){
			if(y == ff) continue;
			dfs(y, now);
			pre[now] = max(pre[now], 1 + pre[y]);
		}
	}
	void solve(){
		int res = 1e18;
		for(int i = 1; i <= n; i++){
			dfs(i, 0);
			for(int j = 1; j <= n; j++){
				if(j == i) continue;
				int dis = 0;
				int tx = j;
				int ans = 0;
				while(fa[tx] != i){
					int lst = tx;
					tx = fa[tx];
					dis ++;
					int tt = 0;
					for(auto y: e[tx]){
						if(y == fa[tx] || y == lst) continue;
						tt = max(tt, pre[y] + 1);
					}
					tt += min(dis, dep[tx] - 1);
					ans = max(ans, tt); 
				}
				priority_queue<pair<int, int> > q;
				for(auto y: e[j]){
					if(y != fa[j]){
						q.push({pre[y], y});
					}
				}
				for(auto y: e[i]){
					if(y != tx){
						q.push({pre[y], y});
					}
				}
				
				
				int ok = t - 2;
				while(q.size()){
					if(!ok) break;
					ok --;
					pair<int, int> tt = q.top(); q.pop();
					for(auto y: e[tt.second]){
						if(y != fa[tt.second]){
							q.push({pre[y], y});
						}
					}
				}
				if(q.size())
				ans = max(ans, q.top().first + 1);
				
				res = min(res, ans);
			}
		}
		cout << res << '\n';
	}
}
namespace Sub2{
	bool check(int mid){
		int pos1 = mid, pos2 = n / 2 + 1 - mid;
		if(pos1 + t - 1 >= pos2) return 1;
		int len = pos2 - pos1 - t + 2 - 1;
		return (len + 1) / 2 + 1 <= mid;
	}
	void solve(){
		if(n == t){
			cout << 0 << '\n';
			return ;
		}
		int l = 1, r = n;
		int ans = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid)){
				r = mid - 1;
				ans = mid;
			}
			else{
				l = mid + 1;
			}
		}
		cout << ans << '\n';
	}
}
void work(){
	n = read();
	t = read();
	for(int i = 1; i <= n; i++){
		e[i].clear();
	}
	for(int i = 1; i < n; i++){
		int x = read(), y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if(n <= 100){
		Sub1::solve();
		return ;
	}
	if(ICS >= 13 && ICS <= 14){
		Sub2::solve();
		return ;
	}	
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ICS = read();
	TCS = read();
	while(TCS --){
		work();
	}
	return 0;
}
