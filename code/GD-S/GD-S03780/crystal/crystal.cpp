#include<bits/stdc++.h>
namespace kimi{
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;
const int maxn = 1e6 + 10;
int n, m;
int A[maxn], sum[maxn];
int check(int x, int l, int r){
	return x * (r - l + 1) - (sum[r] - sum[l - 1]) <= m;
}
void mian(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1, greater<int>());
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + A[i];
	int ans = 1;
	for(int i = 1; i <= n; i++){
		int l = i + 1, r = n;
		while(l <= r){
			int mid = (l + r) / 2;
			if(check(A[i], i, mid)) l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, min(l - 1, n) - i + 1);
	}
	cout << ans << endl;
}
}using namespace kimi;
signed main(){
	//freopen("data.txt", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0); 
	int Test = 1;
	//cin >> Test;
	while(Test--) mian();
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

315275
*/
