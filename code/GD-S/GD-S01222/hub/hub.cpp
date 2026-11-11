#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c,T,n,k,a[N],dep[N],len[N],sz[N],sl[N],num[N];
vector<int>g[N];
void init(){
	for (int i = 1;i <= n;i++){
		g[i].clear();
	}
}
void dfs(int x,int fa,int mid){
	dep[x] = dep[fa] + 1;
	len[x] = 0; sl[x] = 0;
	for (auto y : g[x]){
		if (y == fa) continue;
		dfs(y,x,mid);
		len[x] = max(len[x],len[y]+1);
		sz[x] += sz[y];
		if (sz[y]) ++num[x];
	}
	if (len[x] >= mid) a[x] = 1,++sz[x];
}
void dfs2(int x,int fa,int mid,int p,int mx,int rt){
	for (auto y : g[x]){
		if (y != fa && !a[y]){
//			if(rt==2&&p==3)cout << y << ' ' << num[y] << endl;
			if (len[y] + dep[y] - dep[rt] > mid) mx = max(mx,len[y]+1);
		} 
	}
	if (mx) ++ mx;
//	if (rt == 2 && p == 3) cout << x << ' ' << mx << endl;
	if (mx <= mid) ++ sl[p];
	for (auto y : g[x]){
//		cout<<p << ' '<<y<<endl;
		if (y == fa) continue;
//		cout << y << ' ' << a[y]<< ' ' << num[y] << endl;
		if (a[y] && num[y] == 1 && dep[y]-dep[p]<mid*2){
			dfs2(y,x,mid,p,mx,rt);
		}
	}
}
bool chk(int mid){
	for (int rt = 1;rt <= n;rt++){
//		cout << "rt = " << rt << endl;
		for (int i = 1;i <= n;i++) a[i] = dep[i] = len[i] = sl[i] = sz[i] = num[i] = 0;
		dfs(rt,0,mid); 
		for (auto y : g[rt]){
			if (num[y] == 1){
				dfs2(y,rt,mid,y,0,rt);
			} 
//			if (sz[rt] - sl[y] <= ) cout << "AAAAAAAAAA" << endl;
//			cout<<y << ' ' << sz[rt] << ' ' << sl[y] << ' ' << num[y] << endl;
			if (sz[rt] - min(sl[y],sz[y]-1) <= k) return 1;
		}
	}
//	cout << "false" << endl;
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while (T--){
		cin >> n >> k;
		init();
		for (int i = 1;i < n;i++){
			int x,y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x); 
		}
		if (n <= k){
			cout << "0\n";
			continue;
		}
		int l = 1,r = n;
		while (l < r){
			int mid = (l + r) >> 1;
//			cout<<"chk : " << l <<' ' << r << "           " << mid << endl;
			if (chk(mid)) r = mid;
			else l = mid + 1;
//			cout << l << ' ' << r << endl;
		}
		cout << l << '\n';
	}
	return 0;
}


/*




0 1
6 5
1 2
2 5
4 5
5 3
3 6

0 1
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

