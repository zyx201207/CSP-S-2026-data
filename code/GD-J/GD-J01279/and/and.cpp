#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cnt[50][2];
ll n, m, a[200005];
int qp(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i < 50; i++)
		cnt[i][0] = -1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++){
		int p = 0;
		for(int j = a[i]; j > 0; j /= 2){
			if(j % 2 == 0){
				cnt[p][0] = 0;
			}
			else
				cnt[p][1]++;
			p++;
		}
		for(int j = p; j <= 31; j++){
			cnt[j][0] = 0;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= 31; i++)
		if(cnt[i][0] == -1 && cnt[i][1] > 0)
			ans += qp(2, i);
	for(int i = m + 1; i <= n; i++){
		int p = 0;
		for(ll j = a[i - m]; j > 0; j /= 2){
			if(j % 2 != 0)
				cnt[p][1]--;
			else
				cnt[p][0] = 0;
			p++;
		}
		bool f = false;
		for(int j = 31; j >= p; j--){
			if(cnt[j][1] > 0)
				f = true;
			if(f == true)
				cnt[j][0] = -1;
		}
		p = 0;
		for(ll j = a[i]; j > 0; j /= 2){
			if(j % 2 != 0)
				cnt[p][1]++;
			else
				cnt[p][0] = 0;
			p++;
		}
		ll k = 0;
		for(int j = 0; j <= 31;	j++){
			if(cnt[j][0] == -1 && cnt[j][1] > 0)
				k += qp(2, j);
		}
		ans = max(ans, k);
	}
	cout << ans;
	
	return 0;
}
