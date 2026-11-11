//1s 1G
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
#define Mid auto mid = (l + r) / 2
#define i128 __int128
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
const int N = 5e5 + 5;
int s[N], n, pre[N], m;
int clac(int l, int r){
	return s[r] * (r - l + 1) - (pre[r] - pre[l - 1]);
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
//		s[i] += 1000000000000LL;
	}
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; i ++){
		pre[i] = pre[i - 1] + s[i];
	}
	int ans = 1;
	for(int i = 1; i <= n; i ++){
		int l = 1, r = i, res = i;
		while(l <= r){
			Mid;
			if(clac(mid, i) <= m){
				res = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		cmax(ans, i - res + 1);
//		cerr << clac(res, i) << "\n";
//		cerr << i << " " << res << " " << s[i] << " " << pre[i] << " " << pre[res - 1] << "\n";
	}
	cout << ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
}
/*
luogu : bugaboost114514
Oct31==Dec25?
*/

