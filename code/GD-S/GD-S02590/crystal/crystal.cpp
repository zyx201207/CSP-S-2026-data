#include<bits/stdc++.h>
using namespace std;
/*

*/
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m, ans;
ll arr[N];
queue<ll> q;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	if(n == 1){
		cout << 1;
		return 0;
	}
	sort(arr + 1, arr + 1 + n);
	ll sum = 0, num = 0, cnt = 1;
	for(int l = 1, r = 2; r <= n; ++r){
		num = arr[r] - arr[r - 1];
		if(sum - m + cnt * num > 0){
			if(num > m){
				sum = 0;
				cnt = 1;
				l = r;
			}
			else{
				while(l < r && sum - m + cnt * num > 0){
					sum -= arr[r - 1] - arr[l];
					++l;
					--cnt;
				}
				if(l < r){
					sum += cnt * num;
					++cnt;
				}
			}
		}
		else{
			sum += cnt * num;
			++cnt;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 1000000
1 2 4 8 9

6 10
-9999 -999 1 2 4 123

7 3
1 2 4 123 123 123 -123

1 123456789
987654321

2 10
-999 1028
*/
