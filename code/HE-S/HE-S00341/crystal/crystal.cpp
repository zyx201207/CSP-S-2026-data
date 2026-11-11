#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 10;

int n;
ll a[N], m, diff[N], sum[N];

bool check(ll mid){
	ll mn = 2e18;
	for(int l = 1; l + mid - 1 <= n; l++){
		int r = l + mid - 1;
		mn = min(mn, mid * a[r] - (sum[r] - sum[l - 1]));	
	}
	if(mn > m){
		return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = n;
	while(l < r){
		ll mid = (l + r + 1) >> 1;
		if(check(mid)){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}
