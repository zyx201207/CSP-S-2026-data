#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 500005;

ll n, m;
ll a[MAXN];
ll b[MAXN];
int ans = 1;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n - 1; i++)
		b[i] = a[i + 1] - a[i];
	int l = 1, r = 1;
	ll need = 0;
	ll now = a[1];
	for(l = 1; l <= n; l++){
		while(r + 1 <= n && need + b[r] * (r - l + 1) <= m){
			need += b[r] * (r - l + 1);
//			cout << need <<"\n";
			r++;
			now = a[r];
			ans = max(r - l + 1, ans);
		}
		need -= now - a[l];
//		cout << need <<"\n";
	}

	cout << ans;
} 
