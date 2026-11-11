#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[500005],ans = 0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++){ 
		cin >> a[i];
	}
	sort(a,a + n);
	cout << ans;
	return 0;
}
