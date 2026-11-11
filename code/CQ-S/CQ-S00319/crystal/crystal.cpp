#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010;
namespace cza{
	int n, m;
	int a[N];
	int pre[N];
	int main(){
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= n; i++){
			pre[i] = pre[i - 1] + a[i];
		}
		int pos = 1, ans = 1;
		for(int i = 1; i <= n; i++){
			while(a[i] * (i - pos + 1) - (pre[i] - pre[pos - 1]) > m) pos++;
			ans = max(ans, i - pos + 1);
		}
		cout << ans;
		return 0;  
	}
}
signed main(){
	return cza::main();
}
