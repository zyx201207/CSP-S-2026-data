#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
namespace cza{
	int Cid, T;
	int n, k;
	vector<int> ve[N];
	int mxdep[N], fmxdep[N];
	int son[N];
	int seson[N];
	int thson[N];
	int tmp[N << 1];
	int tmp2[N << 1];
	int *mi[N];
	int *mi2[N];
	int *tcnt;
	int lim[N];
	int fa[N];
	void dfs(int u, int f){
		fa[u] = f;
		mxdep[u] = 0;
		son[u] = seson[u] = thson[u] = 0;
		mxdep[0] = -1;
		for(int v : ve[u]){
			if(v == f) continue;
			dfs(v, u);
			mxdep[u] = max(mxdep[u], mxdep[v] + 1);
			if(mxdep[v] > mxdep[son[u]]) thson[u] = seson[u], seson[u] = son[u], son[u] = v;
			else if(mxdep[v] > mxdep[seson[u]]) thson[u] = seson[u], seson[u] = v;
			else if(mxdep[v] > mxdep[thson[u]]) thson[u] = v;
		}
	}
	void dfs2(int u, int t){
		mi[u] = tcnt;
		tcnt++;
		if(son[u]) dfs2(son[u], t);
		for(int v : ve[u]){
			if(v == fa[u] or v == son[u]) continue;
			dfs2(v, v);
		}
	}
	void dfs3(int u){
		if(u == 1){
			fmxdep[u] = 0;
		}
		for(int v : ve[u]){
			if(v == fa[u]) continue;
			if(v == son[u]){
				fmxdep[v] = max(fmxdep[u], (!seson[u] ? 0 : mxdep[seson[u]] + 1)) + 1;
			}else{
				fmxdep[v] = max(fmxdep[u], mxdep[son[u]] + 1) + 1;
			}
			dfs3(v);
		}
	}
	int LIM;
	int dp[N], fdp[N];
	int get(int d){
		return max(0, LIM - d);
	}
	void solve(int u){
		for(int v : ve[u]){
			if(v == fa[u]) continue;
			solve(v);
		}
		mi[u][0] = (mxdep[u] >= LIM);
		for(int v : ve[u]){
			if(v == fa[u]) continue;
			mi[u][0] += mi[v][0];
		}
		if(!son[u]) lim[u] = 0;
		else lim[u] = min(lim[son[u]] + 1, get(!seson[u] ? 0 : mxdep[seson[u]] + 1));
		dp[u] = min(mi[u][0], mi[u][lim[u]]);
//		cout << "mi[" << u << "][0]" << ' ' << mi[u][0] << '\n';
	}
	int *fmi[N];
	int flim[N];
	void solve2(int u){
		if(u == 1) fdp[u] = 0;
//		cout << u << ' ' << fdp[u] << '\n';
		for(int v : ve[u]){
			if(v == fa[u]) continue;
			int last;
			
			if(v == son[u]){
				if(seson[u] == 0 or fmxdep[u] > mxdep[seson[u]] + 1){ //继承fa，剩下最长的是seson 
					if(u == 1){
						fmi[u] = mi[u];
						last = fmi[u][0];
						fmi[u][0] = (fmxdep[u] >= LIM);
						flim[u] = 0;
					}else{
						fmi[u] = fmi[fa[u]] - 1;
						last = fmi[u][0];
						fmi[u][0] = (fmxdep[u] >= LIM) + mi2[u][0] - (mxdep[u] >= LIM) - mi2[v][0] + (u == 1 ? 0 : fmi[fa[u]][0]);
						flim[u] = min(flim[fa[u]] + 1, get(!seson[u] ? 0 : mxdep[seson[u]] + 1));
					}
				}else{ //继承sedep，剩下最长的是max(th,fa) 
					fmi[u] = mi[seson[u]] - 1;
					last = fmi[u][0];
					fmi[u][0] = (mxdep[seson[u]] + 1 >= LIM) + mi2[u][0] - (mxdep[u] >= LIM) - mi2[v][0] + (u == 1 ? 0 : fmi[fa[u]][0]);
					flim[u] = min(lim[seson[u]] + 1, get(max(!thson[u] ? 0 : mxdep[thson[u]] + 1, fmxdep[u])));
				}
			}else if(v == seson[u]){
				if(fmxdep[u] > mxdep[son[u]] + 1){ //继承fa，剩下最长的是son 
					fmi[u] = fmi[fa[u]] - 1;
					last = fmi[u][0];
					fmi[u][0] = (fmxdep[u] >= LIM) + mi2[u][0] - (mxdep[u] >= LIM) - mi2[v][0] + (u == 1 ? 0 : fmi[fa[u]][0]);
					flim[u] = min(flim[fa[u]] + 1, get(mxdep[son[u]] + 1));
				}else{ //继承son，剩下最长的是max(th,fa) 
					fmi[u] = mi[son[u]] - 1;
					last = fmi[u][0];
					fmi[u][0] = (mxdep[son[u]] + 1 >= LIM) + mi2[u][0] - (mxdep[u] >= LIM) - mi2[v][0] + (u == 1 ? 0 : fmi[fa[u]][0]);
					flim[u] = min(lim[son[u]] + 1, get(max(!thson[u] ? 0 : mxdep[thson[u]] + 1, fmxdep[u])));
				}
			}else{
				if(fmxdep[u] > mxdep[son[u]] + 1){ //继承fa，剩下最长的是son
					fmi[u] = fmi[fa[u]] - 1;
					last = fmi[u][0];
					fmi[u][0] = (fmxdep[u] >= LIM) + mi2[u][0] - (mxdep[u] >= LIM) - mi2[v][0] + (u == 1 ? 0 : fmi[fa[u]][0]);
					flim[u] = min(flim[fa[u]] + 1, get(mxdep[son[u]] + 1));
				}else{ //继承son，剩下最长的是max(se,fa) 
					fmi[u] = mi[son[u]] - 1;
					last = fmi[u][0];
					fmi[u][0] = (mxdep[son[u]] + 1 >= LIM) + mi2[u][0] - (mxdep[u] >= LIM) - mi2[v][0] + (u == 1 ? 0 : fmi[fa[u]][0]);
					flim[u] = min(lim[son[u]] + 1, get(max(mxdep[seson[u]] + 1, fmxdep[u])));
				}
			}
			fdp[v] = min(fmi[u][0], fmi[u][flim[u]]);
			solve2(v);
			fmi[u][0] = last;
		}
	}
	bool check(int mid){
		LIM = mid;
		solve(1);
		for(int i = 0; i < (N << 1); i++){
			tmp2[i] = tmp[i];
		}
		for(int i = 1; i <= n; i++){
			mi2[i] = tmp2 + (mi[i] - tmp);
		}
		solve2(1);
		if(dp[1] <= k) return 1;
		for(int i = 2; i <= n; i++){
			if(max(1, dp[i]) + max(1, fdp[i]) <= k) return 1;
		}
		return 0;
	}
	void clear(){
		for(int i = 1; i <= n; i++){
			ve[i]. clear();
			fa[i] = 0;
		}
	}
	int main(){
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> Cid >> T;
		while(T--){
			cin >> n >> k;
			for(int i = 1, u, v; i < n; i++){
				cin >> u >> v;
				ve[u]. push_back(v);
				ve[v]. push_back(u);
			}
			dfs(1, 0);
			tcnt = tmp + 1000010;
			dfs2(1, 1);
			dfs3(1);
//			for(int i = 1; i <= n; i++){
//				cout << i << ": "<< mxdep[i] << ' ' << fmxdep[i] << ' ' << son[i] << ' ' << seson[i] << ' ' << thson[i] << '\n';
//			}
//			check(1);
//			return 0;
			int l = 0, r = n, ans = n;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(check(mid)) r = mid - 1, ans = mid;
				else l = mid + 1;
			}
			cout << ans << '\n';
			clear();
		}
		return 0;
	}
}
signed main(){
	return cza::main();
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

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

*/
