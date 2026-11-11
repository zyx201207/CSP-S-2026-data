#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+9;
int n;
ll m, a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	ll sum = 0;
	int ans = 1;
	for(int i = 1, j = 1; i <= n; i++){
		while(sum > m && j < i){
			sum -= a[i]-a[j];
			j++;
		}
		ans = max(ans, i-j+1);
		if(i < n){
			sum += (a[i+1]-a[i])*(i-j+1);
		}
	}
	cout << ans << endl;
	return 0;
}
