#include <bits/stdc++.h>
#define fs first
#define sc second
#define int long long
#define vi vector<int> 
#define For(i,x,y) for(int i = x;i <= y;i ++)
#define For_(i,x,y) for(int i = x;i <= y;i ++)
#define pb push_back
#define endl '\n'
#define x0 _x0_
#define y1 _y1_
const int N = 1e6 + 5;
using namespace std;
void gmax(int &x,int y) {
	x = max(x,y);
	return ;
}int n,k;
vector<int> mp[N];
int mid = 0;
int dep[N];
int vis[N];
int f[N];
int son[N];
int vis2[N];
int dfs(int x,int fa){
	dep[x] = dep[fa] + 1;
	int res = dep[x];
	for(auto it:mp[x]) if(it!=fa) {
		gmax(res,dfs(it,x)); // max dep son
		son[x] += vis[it];
	}if(res - dep[x] >= mid) vis[x] = 1;
	if(res - dep[x] == mid) vis2[x] = 1;
	return res;
}void dfs2(int x,int fa){
	for(auto it : mp[x]) if(it!=fa) {
		dfs2(it,x);
		if(son[x] == 1 && vis[x] && vis[it] && !vis2[x]) {
			f[x] = max(f[x] ,f[it] + 1);
		}
	}
}
bool check(){
	For(root,1,n) {
//		if(n > 4000  ) root += rng() % 10000; 
		For(i,0,n + 1) dep[i] = vis[i] = vis2[i] = f[i] = son[i] = 0;
		dfs(root,0);
		dfs2(root,0);
		int ans = 0;
		int res = 0;
		For(i,1,n) res += vis[i];
		For(i,1,n) gmax(ans,f[i]);
		
		
		if(son[root] == 2) {
			int cnt = 0;
			for(auto it : mp[root]) if(vis[it]){
				cnt += f[it];
			}gmax(ans,cnt + 1);
		}
		
//		if(mid == 1 && root == 1) {
//			
//			For(i,1,n) cout << vis[i] << ' ';
//			cout << endl;
//			For(i,1,n) cout << f[i] << ' ';
//			cout << endl;
//			cout << res << ' ' << son[root] << ' ' << ans << endl;
//			
//		}
		if(res - min(ans,mid * 2 ) <= k) return true;
		
	}
	return false;
}
void solve(){
	cin >> n>>k;
	For(i,0,n+1) mp[i].clear();
	For(i,1,n - 1){
		int u,v;
		cin >> u >> v;
		mp[u].pb(v),mp[v].pb(u);
	}
	int l = 0,r = n;
	while(l + 3 <= r) {
		mid = (l + r) >> 1;
		if(check()) r = mid;
		else l = mid;
	}For(i,l,r) {
		mid = i;
		if(check()) {
			cout << i << endl;
			return ;
		}
	}
}signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T = 1;
	int c = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> c;
	cin >> T;
	while(T--) solve();
	return 0;
}

/*
0 1
8 2
1 2
2 3
2 4 
1 5
5 6
6 7
6 8

1


0 1
10 3
1 2 
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

2

0 1
10 2
1 2
1 3
2 4
4 5
4 6
5 7
7 8
7 9
8 10

2

0 1
8 1
1 2
1 3
1 4 
1 5
1 6
1 7
1 8

1




0 1
15 1
1 2
2 5
4 3
3 5
5 6
6 7
5 13
13 10
8 9
9 10
10 11
11 12
10 14
14 15


0 1
20 3
1 2
2 3
3 4
4 5
5 6
3 7
7 8
7 11
8 10
8 9
11 12
11 13
5 17
15 17
15 14
15 16
17 18
18 20
18 19




*/


