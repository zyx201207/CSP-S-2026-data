#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
#define pb push_back
#define str string
#define db double
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t.sizeof(a))
const ll INF = 0x3f3f3f3f;
const ll mod = 998244353;
const int maxn = 2e6+10;
const int maxm = 2e5+10;
const db eps = 1e-6;
int n,m,k;
int fa[maxn];
vector<int> G[maxn];
void dfs(int x,int ff,int* dis) {
	if(ff == 0) dis[x] = 0;
	fa[x] = ff;
	for(int to : G[x]) if(to != ff) {
		dis[to] = dis[x] + 1;
		dfs(to,x,dis);
	}
}
vector<int> vec;
bool vis[maxn];
vector<int> cnt[maxn];
int dep[maxn],mx[maxn];
void dfs2(int x,int ff,int id,int cur) {
//	cerr<<x<<' '<<id<<'\n';
	dep[x] = cur;
	if((int)cnt[id].size() <= cur) {
		cnt[id].pb(1);
	} else {
		cnt[id][cur]++;
	}
	mx[x] = 0;
	for(int to : G[x]) if(to != ff && !vis[to]) {
		dfs2(to,x,id,cur+1);
		mx[x] = max(mx[x],mx[to]+1);
	}
}
int lt[maxn],rt[maxn],len[maxn];
int prel[maxn],prer[maxn],sufl[maxn],sufr[maxn];
int pre[maxn],suf[maxn];
int lst[maxn];
int dfs3(int x,int ff,int t,int st) {
	if(mx[x] < t) {
		lst[x] = INF; return 0;
	}
	if(mx[x] == t) {
		lst[x] = dep[x]; 
		return 1;
	} 
	lst[x] = INF;
	int ret = 0,c = 0,tmp1 = 1,lim = dep[x],tmp2 = 0;
	if(dep[x] <= t) lim = -t;
	for(int to : G[x]) if(to != ff && !vis[to]) {
		if(mx[to] + dep[to] <= t) continue;
		int tmp = dfs3(to,x,t,st);
		if(tmp == 0) {
			lim = max(lim,mx[to]+dep[to]);
		} else {
			c++;
			tmp2 = max(tmp2,(lst[to]-dep[x]-1));
			tmp1 += (lst[to]-dep[x]-1);
			lst[x] = min(lst[x],lst[to]);
			ret += tmp;
		}
	}
	if(c > 1) {
		ret += tmp1;
		if(ff == 0) ret -= tmp2;
		lst[x] = dep[x];
	} else {
		if(lst[x]-dep[x]+lim > t) {
			ret += lst[x]-(t+dep[x]-lim);
			lst[x] = t+dep[x]-lim;
		}
	}
//	if(st == 30) {
//		cerr<<"DFS3 : "<<x<<' '<<ff<<' '<<t<<' '<<ret<<' '<<lst[x]<<'\n';
//	}
	return ret;
}
bool check(int d) {
	int sum = 0;
	for(int i = 0; i <= m; i++) pre[i] = suf[i] = 0;
	for(int i = 0; i < m; i++) {
		if(len[i] < d) {
			lt[i] = i-(d-len[i]); rt[i] = i+(d-len[i]);
		} else {
			lt[i] = rt[i] = i;
			sum += cnt[i][len[i]-d]-1;
//			cerr<<' '<<i<<' '<<len[i]<<' '<<cnt[i][len[i]-d]<<'\n';
		}
	}
	for(int i = 0,l = m,r = 0; i < m; i++) {
		l = min(l,rt[i]); r = max(r,lt[i]);
		prel[i] = l; prer[i] = r;
		if(l > r) pre[i] = 1;
		else pre[i] = r-l+1;
	}
	for(int i = m-1,l = m,r = 0; i >= 0; i--) {
		l = min(l,rt[i]); r = max(r,lt[i]);
		sufl[i] = l; sufr[i] = r;
		if(l > r) suf[i] = 1;
		else suf[i] = r-l+1;
	}
	int mn = n+1;
	for(int i = 0; i+1 < m; i++) {
		mn = min(mn,pre[i]+suf[i+1]);
	} 
	int ret = mn+sum;
	for(int i = 1; i+1 < m; i++) if(len[i] > d) {
		int tmp = sum-(cnt[i][len[i]-d]-1);
		int l = min(prel[i-1],sufl[i+1]),r = max(prer[i-1],sufr[i+1]);
		if(l > r) tmp += 1;
		else tmp += r-l+1;
		int tmp2 = dfs3(vec[i],0,d,i);
		ret = min(tmp+tmp2,ret);
//		cerr<<' '<<i<<' '<<len[i]<<' '<<sum<<' '<<(cnt[i][len[i]-d]-1)<<' '<<tmp<<' '<<tmp2<<'\n';
	}
//	cerr<<n<<' '<<m<<' '<<d<<' '<<mn<<' '<<sum<<' '<<k<<'\n';
//	for(int i = 0; i < m; i++) { cerr<<" "<<"("<<lt[i]<<","<<rt[i]<<")"; } cerr<<'\n';
	return ret <= k;
}
int dis[maxn];
void Solve() {
	for(int i = 1; i <= n; i++) G[i].clear();
	cin >> n >> k;
	for(int i = 1,u,v; i < n; i++) {
		cin >> u >> v;
		G[u].pb(v); G[v].pb(u);
	}
	if(k == n) {
		cout<<0<<'\n';
		return;
	}
	vec.clear();
	dfs(1,0,dis);
	int u = max_element(dis+1,dis+n+1)-dis;
	dfs(u,0,dis);
	int v = max_element(dis+1,dis+n+1)-dis;
	for(int x = v; x != u; x = fa[x]) {
		vec.pb(x);
	}
	vec.pb(u);
	m = vec.size(); 
	for(int i = 1; i <= n; i++) vis[i] = false;
	for(int i = 0; i < m; i++) vis[vec[i]] = true;
	for(int i = 0; i < m; i++) {
		dfs2(vec[i],0,i,0);
		len[i] = cnt[i].size()-1;
		for(int j = 1; j < (int)cnt[i].size(); j++) {
			cnt[i][j] += cnt[i][j-1];
		}
	}
	int l = 1,r = n;
	while(l < r) {
		int mid = (l+r) >> 1;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	cout<<l<<'\n';
	for(int i = 0; i < m; i++) cnt[i].clear();
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cc,tt; cin >> cc >> tt; while(tt--)
	Solve();
	return 0;
}

