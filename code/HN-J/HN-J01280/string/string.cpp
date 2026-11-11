#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, ans, a[N];
char c[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for(int posl = 1, posr = n; posl < posr; ){
		int val = min(a[posl], a[posr]);
		a[posl] -= val, a[posr] -= val;
		if(c[posl] != c[posr]) ans += val;
		if(!a[posl]) posl++;
		else posr--;
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

