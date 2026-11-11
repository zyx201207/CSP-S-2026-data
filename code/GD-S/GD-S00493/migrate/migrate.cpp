#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, T, n, d, x[N], cur, las, ans, cnt2, dis[N], cnt[N], r[N], fl[N];
inline void mian(){
	ans = 0;
	cin >> n >> d;
	memset(r, 0, sizeof(int) * (n + 1));
	memset(fl, 0, sizeof(int) * (n + 1));
	for (int i = 1;i <= n;i++)cin >> x[i];
	for (int i = 1;i <= n;i++){
//		cout << "------" << i << "\n";
		dis[i] = 0, cnt[i] = 0;
		for (int j = i + 1;j <= n;j++){
			int pre = lower_bound(x + 1, x + 1 + j, x[j] - d) - x;
			if (pre < i)pre = i;
//			cout << "#" << pre << "\n";
			pre = r[fl[pre]];
			if (pre == j)dis[j] = LLONG_MAX;
			else{
				dis[j] = dis[pre] + 1;
				if (dis[j] >= 2 && x[j] - x[pre - 1] <= d && x[j] - x[pre - 2] > d)cnt[j] = cnt[pre] + 1;
				else cnt[j] = cnt[pre];
				if (cnt[j] == 1)ans++;
			}
			if (dis[j] ^ dis[j - 1]){
				fl[j] = fl[j - 1] + 1;
			}else fl[j] = fl[j - 1], r[fl[j]] = j;
//			cout << "@" << pre << " " << j << "\n";
//			cout << "#" << dis[j] << " " << cnt[j] << "\n"; 
		}
	} 
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	for (cin >> c >> T;T;T--)mian();
	return 0;
}
/*
10 3
-10 -7 -4 -3 -2 -1 0 1 4 7 
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
/*
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
*/ 
