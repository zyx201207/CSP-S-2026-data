#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N];
int ans = 0;
int lowbit(int x){
	return (x & -x);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, [](int x, int y){
		return x > y;
	});
	
	if(m == 1){
		cout << a[1];
		return 0;
	} else if(m == n){
		ans = a[1];
		for(int i = 2; i <= n; i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	} else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; i++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	} else if(n <= 20){
		int sum = 1;
		for(int i = 1; i <= n; i++){
			sum = a[i];
			for(int j = 1; j < m; j++){
				sum &= a[i + j];
			}
			ans = max(ans, sum);
		}
		cout << ans;
		return 0;
	} else if(m == n - 1){
		int sum = a[1];
		for(int i = 1; i <= n; i++){
			for(int j = 1; i <= n; i++){
				if(j == i) {
					if(sum == a[1] && i == 1){
						sum = a[2];
					}
					continue;
				}
				sum &= a[j];
			}
			ans = max(ans, sum);
		}
		cout << ans;
		return 0;
	} else{
		cout << 3;
	}
	return 0;
}

