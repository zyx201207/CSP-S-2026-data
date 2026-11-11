#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

const int N = 2000005;
int c,t,n;
long long d,x[N];
int head[N],to[N],nxt[N],tot;
void add(int u,int v){
	nxt[++tot] = head[u];
	to[head[u] = tot] = v;
}
#define fore(u,v) for(int ptr = head[u],v = to[ptr];ptr;v = to[ptr = nxt[ptr]])
const long long MOD = 131817137,inf = 4e18;
int dis[N];
long long dp[N];
queue<int> qu;
void bfs(int st){
	for(int i = 1;i <= n;i++) dis[i] = 0x3f3f3f3f,dp[i] = 0;
	dp[st] = 1,dis[st] = 0;
	qu.push(st);
	while(qu.size()){
		int u = qu.front();qu.pop();
		fore(u,v){
			if(dis[v] < dis[u] + 1) continue;
			if(dis[v] == dis[u] + 1){
				dp[v] += dp[u];
				dp[v] = min(dp[v],inf);
				continue;
			}
			dis[v] = dis[u] + 1;
			dp[v] = dp[u];
			qu.push(v);
		}
	}
}
void brute(){
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(abs(x[i] - x[j]) <= d) add(i,j);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		bfs(i);
		for(int j = i + 1;j <= n;j++)
			if(dp[j] == 2) ans++;
	}
	cout << ans << '\n';
}
void solve2(){
	if(n == 1){
		cout << "0\n";
		return ;
	}
	long long r = d / (x[2] - x[1]);
	cout << (r <= 1? 0ll : max(0ll,n - (r << 1) + 1)) << '\n';
}

vector<long long> vec;
struct BIT{
	#define lowbit(x) (x & -x)
	long long tr[N << 1];
	void add(int x,long long y){while(x <= (n << 1)) tr[x] += y,x += lowbit(x);}
	long long ask(int x,long long y = 0){while(x) y += tr[x],x -= lowbit(x);return y;}
	long long qry(int l,int r){return ask(r) - ask(max(0,l - 1));}
}T;
void solve3(){
	// vec.clear();
	// for(int i = 1;i <= n;i++) vec.emplace_back(x[i]),vec.emplace_back(x[i] - d);
	// sort(vec.begin(),vec.end());
	// vec.erase(unique(vec.begin(),vec.end()),vec.end());
	// int tot = vec.size();
	// auto find = [&] (long long x) -> int{return lower_bound(vec.begin(),vec.end(),x) - vec.begin() + 1;};
	// for(int i = 1;i <= tot;i++) T.tr[i] = 0;
	// long long cnt1 = 0,cnt2 = 0;
	// int ptr = 2;
	// for(int i = 2;i <= n;i++){
		// if(i < n){
			// while(ptr < i && x[i+1] - x[ptr] > d) T.add(find(x[ptr-1]),-1),ptr++;
		// }
		// cnt1 += T.qry(find(x[i] - d),tot);
		// if(i > 1) T.add(find(x[i-1]),1);
	// }
	// ptr = 1;
	// for(int i = 1;i < n;i++){
		// while(ptr < i && x[i+1] - x[ptr] > d) ptr++;
		// cnt2 += (i - ptr);
	// }
	// ptr = 2;
	// for(int i = 2;i <= n;i++){
		// while(ptr < i && x[i] - x[ptr-1] > d) ptr++;
		// cnt2 += (i - ptr);
	// }
	// cnt2 -= cnt1;
	// cout << cnt1 - cnt2 << '\n';
}
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> x[i];
	if(n <= 5000) return brute();
	if(c == 11 || c == 12) return solve2();
	if(c == 13 || c == 14) return solve3();
}
void clear(){
	for(int i = 1;i <= n;i++) head[i] = 0,tot = 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--) solve(),clear();
	
	return 0;
}