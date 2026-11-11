#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define int ll
#define inf (1e18 + 10)
const int N = 2e5 + 10;
int n, m, arr[N];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	if(n == m){
		int a, ans;
		for(int i = 0;i < n;i ++){
			cin >> a;
			if(i == 0){
				ans = a;
			}else{
				ans = (ans & a);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 1){
		int a, ans = -999;
		for(int i = 0;i < n;i ++){
			cin >> a;
			ans = max(ans, a);
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		int ans = -999;
		for(int i = 0;i < n;i ++){
			cin >> arr[i];
		}
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < n;j ++){
				if(i == j){
					continue;
				}
				ans = max(ans, (arr[i] & arr[j]));
			}
		}
		cout << ans;
	}
	return 0;
}
