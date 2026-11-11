#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005], num[500005];
ll check(ll x, ll y){
	ll ans = num[x] - num[y] - (a[x] - a[y])*(y - 1);
	return ans;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool b = true;
	int n, m, flag;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 2)
			flag = a[2] - a[1];
		else if(i > 2 && b){
			if(a[i] - a[i - 1] != flag)
				b = false;
		}
	}
	if(b == true){
		ll cnt = 0, now = 1;
		for(int i = n - 1; i >= 1; i--){
			cnt += a[n] - a[i];
			if(cnt > m)
				break;
			now ++;
		}
		cout << now;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	num[1] = 0, num[0] = 0;
	for(int i = 2; i <= n; i++){
		num[i] = num[i - 1] + (a[i] - a[i - 1]) * i;
	}
	ll maxn = 1, now = 1, cnt = 0, f, r, l, mid;
	for(int i = 2; i <= n; i++){
		f = check(i, i - maxn + 1);
		if(f >= m)
			continue;
		if(i - maxn + 1 == 1)
			continue;
		l = 1;
		r = i - maxn;
		while(l < r){
			mid = l + (r - l)/2;
			f = check(i, mid);
			if(f > m)
				l = mid + 1;
			else if(f == m){
				maxn = max(maxn, i - mid + 1);
				break;
			}
			else
				r = mid;
		}
		maxn = max(maxn, i - l + 1);
	}
	cout << maxn;
	return 0;
}
