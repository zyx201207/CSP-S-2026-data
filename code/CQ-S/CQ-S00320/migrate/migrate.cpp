//¼×ÍéÁË µ¹±Õ 
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair<int, int>
#define fs first
#define se second
#define lp p * 2
#define rp p * 2 + 1
#define pb push_back
#define all(s) s.begin(), s.end()
#define db double
#define i128 __int128
#define Mid auto mid = (l + r) / 2
using namespace std;
template<class T1, class T2>
void cmax(T1 &a, T2 b){if(a < b)a = b;}
template<class T1, class T2>
void cmin(T1 &a, T2 b){if(a > b)a = b;}
template<class T>
void read(T &x){
	int k = 0;
	char c = getchar();
	while(!isdigit(c))c = getchar();
	while(isdigit(c))k = k * 10 + c - 48, c = getchar();
	x = k;
}
int testcase;
int n, d;
const int N = 2e6 + 5;
int s[N];
namespace N_5000{
	void solve(){
		const int M = 5005;
		for(int i = 1; i <= n; i ++){
			cin >> s[i];
		}
		int lmx[M] = {}, f[M] = {}, dis[M] = {}, pre[M] = {};
		for(int i = 1; i <= n; i ++){
			int l = 1, r = i, res = i;
			while(l <= r){
				Mid;
				if(abs(s[i] - s[mid]) <= d){
					res = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			lmx[i] = res;
		}
		int ans = 0;
		for(int bg = 1; bg <= n - 1; bg ++){
			memset(f, 0, sizeof f);
			memset(dis, 0, sizeof dis);
			memset(pre, 0, sizeof pre);
			int tt = bg;
			f[bg] = 1, pre[bg] = 1;
			for(int j = bg + 1; j <= n; j ++){
				int p = max(lmx[j], bg);
				dis[j] = dis[p] + 1;
				int res = p;
				if(tt < p)tt = p;
				while(dis[tt + 1] == dis[p]){
					tt ++;
				}
				res = tt;
				f[j] = pre[res] - pre[p - 1];
				pre[j] = pre[j - 1] + f[j];
				if(f[j] == 2){
					ans ++;
				}
			}
		}
		cout << ans << "\n";
	}
}
namespace SubA{
	void solve(){
		for(int i = 1; i <= n; i ++){
			cin >> s[i];
		}
		vector<int>lmx(n + 2);
		for(int i = 1; i <= n; i ++){
			int l = 1, r = i, res = i;
			while(l <= r){
				Mid;
				if(abs(s[i] - s[mid]) <= d){
					res = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			lmx[i] = res;
		}
		int ans = 0;
		vector<int>len(n + 2);
		for(int bg = 1; bg <= 1; bg ++){
			vector<int>f(n + 2), dis(n + 2), pre(n + 2);
			f[bg] = 1, pre[bg] = 1;
			for(int j = bg + 1; j <= n; j ++){
				int p = max(lmx[j], bg);
				dis[j] = dis[p] + 1;
				int l = p, r = j - 1, res = p;
				while(l <= r){
					Mid;
					if(dis[mid] == dis[p]){
						res = mid;
						l = mid + 1;
					}
					else {
						r = mid - 1;
					}
				}
				f[j] = pre[res] - pre[p - 1];
				pre[j] = pre[j - 1] + f[j];
				if(f[j] == 2){
					len[j] ++;
				}
			}
		}
		for(int i = 2; i <= n; i ++){
			ans += len[i] * (n - i + 1);
		}
		cout << ans << "\n";
	}
}
namespace SubB{
	void solve(){
		for(int i = 1; i <= n; i ++){
			cin >> s[i];
		}
		vector<int>lmx(n + 2), rmx(n + 2);
		for(int i = 1; i <= n; i ++){
			int l = 1, r = i, res = i;
			while(l <= r){
				Mid;
				if(abs(s[i] - s[mid]) <= d){
					res = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			lmx[i] = res;
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			ans += lmx[i] - 1;
		}
		cout << ans << "\n";
	}
}
void solve(){
	cin >> n >> d;
	if(testcase <= 10){
		N_5000::solve();
	}
	else if(testcase <= 12){
		SubA::solve();
	}
	else if(testcase <= 14){
		SubB::solve();
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T = 1;
	cin >> testcase >> T;
	while(T --){
		solve();
	}
}
/*
luogu : bugaboost114514
Oct31==Dec25?
16:30 1-10 done
16:41 11-12 done and checked
16::49 13-14 done ans checked
17:00 opti 1-10 from n*n*logn -> n*n
17:10 i maybe
CH4 -ed



#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair<int, int>
#define fs first
#define se second
#define lp p * 2
#define rp p * 2 + 1
#define pb push_back
#define all(s) s.begin(), s.end()
#define db double
#define i128 __int128
#define Mid auto mid = (l + r) / 2
using namespace std;
template<class T1, class T2>
void cmax(T1 &a, T2 b){if(a < b)a = b;}
template<class T1, class T2>
void cmin(T1 &a, T2 b){if(a > b)a = b;}
template<class T>
void read(T &x){
	int k = 0;
	char c = getchar();
	while(!isdigit(c))c = getchar();
	while(isdigit(c))k = k * 10 + c - 48, c = getchar();
	x = k;
}
int testcase;
int n, d;
const int N = 2e6 + 5;
int s[N];
int lmx[N], rmx[N];
int lcnt[N], rcnt[N];
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		lcnt[i] = rcnt[i] = lmx[i] = rmx[i] = 0;
	}
	for(int i = 1; i <= n; i ++){
		int l = 1, r = i, res = i;
		while(l <= r){
			Mid;
			if(abs(s[i] - s[mid]) <= d){
				res = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		lmx[i] = res;
	}
	for(int i = 1; i <= n; i ++){
		int l = i, r = n, res = i;
		while(l <= r){
			Mid;
			if(abs(s[i] - s[mid]) <= d){
				res = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		rmx[i] = res;
	}
//	for(int i = 1; i <= n; i ++){
//		if(lmx[i] != i)atl[lmx[i]].pb(i);
//		if(rmx[i] != i)atr[rmx[i]].pb(i);
//	}
	for(int i = n; i >= 1; i --){
		rcnt[i] = 1;
		if(rmx[i] != i)rcnt[i] += rcnt[rmx[i]];
	}
	for(int i = 1; i <= n; i ++){
		lcnt[i] += 1;
//		cerr << lmx[i] << " ";
		if(rmx[i] != i)lcnt[rmx[i]] += lcnt[i];
	}
//	return ;
	for(int i = 1; i <= n; i ++){
		cerr << lmx[i] << " " << rmx[i] << " " << lcnt[i] << " " << rcnt[i] << "\n";
	}
	int ans = 0;
	cerr << "\n";
	for(int i = 2; i <= n - 2; i ++){
		if(rmx[i] >= i + 1 && lmx[i + 1] <= i && lmx[i + 1] != lmx[i + 2] && rmx[i] != rmx[i - 1]){
			ans += (lcnt[i + 1] - 1) * (rcnt[i + 1] - 1);
			cerr << i << " " << i + 1 << " " << lcnt[i + 1] << " " << rcnt[i] << "\n";
		}
		cerr << ans << "\n";
	}
	cout << ans << "\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("migrate3.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	int T = 1;
	cin >> testcase >> T;
	while(T --){
		solve();
	}
}
luogu : bugaboost114514
Oct31==Dec25?
16:30 1-10 done
16:41 11-12 done and checked
16::49 13-14 done ans checked
17:00 opti 1-10 from n*n*logn -> n*n

*/

