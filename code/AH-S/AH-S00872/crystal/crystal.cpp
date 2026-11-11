#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

typedef long long ll;

int n, ans = 1;
ll m;
vector<ll> a;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	
	cin >> n >> m;
	if (m == 0) {
		cout << 1 << '\n';
		return 0;
	}
	
	a.resize(n+1, INT_MIN);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a.begin(),a.end());

	ll d = 0;
	int l=1, r=1;
	
	while (true){
		r++;
		if (r > n) break;
		d += (r-l)*(a[r]-a[r-1]);
		while (d>m){
			d -= a[r]-a[l];
			l++;
			if (r==l)break;
		}
		
		ans = max(ans, r-l+1);
	}
	
	cout << ans << '\n';
	
	return 0;
}
