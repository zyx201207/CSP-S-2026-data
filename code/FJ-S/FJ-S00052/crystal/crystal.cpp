# include <bits/stdc++.h>
using namespace std;
# define ll long long

const int N = 5e5 + 55;// 5211314 to yi 

struct node {
	ll x, pre;
};

node a[N];
ll n, m;
ll ans = 0;

bool cmp (node &a, node &b) {
	return a.x < b.x;
}

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (0);
	
	cin >> n >> m;
	
	for (ll i = 1; i <= n; i++) {
		cin >> a[i].x;
	}
	
	sort (a + 1, a + 1 + n, cmp);
	
	if (a[1].x == a[n].x) {
		cout << n << endl;
		return 0;
	}
	
	for (ll i = 1; i <= n; i++) {
		a[i].pre = a[i - 1].pre + a[i].x;
	}
	
	for (ll i = 1; i <= n; i++) {
		ll nodes = a[i].x; // 当前众数
		ll sum = a[i].x * i - a[i].pre; // 需要操作多少次才能使所有的数都变成众数 
		
//		for (int j = 1; j <= i; j++) {
//			sum += a[i] - a[j];
//		}
		
		if (sum <= m) {
			ans = max (ans, i); // 在限定次数内 
		} else {
			ll j;
			
			if (sum - a[i].x * (i - ans + 1) + a[i - ans].pre > m) {
				continue;
			}
			
			for (j = 1; j <= i - ans + 1;) {
				if (sum <= m) {
					break;
				} else {
					sum -= a[i].x - a[j].x;
					j++;
				}
			} 

			ans = max (ans, i - j + 1);
//			cout << ans << endl;
		}
		
	}
	
	cout << ans << endl;
	
	return 0;
}

// 52春意 （幸运の52，祝福春意你啊所愿皆所得，所向皆所想，平平安安和我一起享受这一生） 
// 虽然我没有那么强，但我会用实际行动证明你所选的我是对的哦！ 
