#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 5;
int n, m, qz[N], a[N], ans;
int zfind(int x){
	int l = 0, r = x;
	while(l + 1 < r){
		int mid = l + r >> 1;
		if(a[x] * (x - mid) - (qz[x - 1] - qz[mid - 1]) <= m) r = mid;
		else l = mid;
	}
	return r;
}
signed main(){
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1); int sum = 0, tmp;
	for(int i = 1;i <= n;i++) qz[i] = qz[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		tmp = zfind(i);
		ans = max(ans, i - tmp + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
完成时间：14:49 
预估100分 
*/ 
