#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const ll MA = pow(2, 31) - 1;
int n, m;
ll a[N];
ll ans;

void baoli(int s, int last, ll cnt){
	if (s == m){
		ans = max(ans, cnt);
		return;
	}
	if (s < m && last == n)
		return;
	if (cnt == 0)
		return;
	baoli(s + 1, last + 1, cnt & a[last + 1]);
	baoli(s, last + 1, cnt);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1){
		for(int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	else if (m == n){
		ans = a[1];
		for(int i = 2; i <= n; i++)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	else if (m == 2){
		for(int i = 1; i < n; i++)
			for(int j = i + 1; j <= n; j++)	
				ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	else if (m == n - 1){
		for(int i = 1; i <= n; i++){
			ll cnt;
			if (i == 1){
				cnt = a[2];
				for(int j = 3; j <= n; j++)
					cnt &= a[j];
			}
			else{
				cnt = a[1];
				for(int j = 2; j <= n; j++)
					if (j != i)
						cnt &= a[j];
			}
			ans = max(ans, cnt);
		}
		cout << ans;
		return 0;
	}
	else{
		baoli(0, 0, MA);
		cout << ans;
		return 0;
	}
	return 0;
}

