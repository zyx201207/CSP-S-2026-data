#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
struct node{
	int cnt;
	char ch;
}a[N];
int n, lc, rc, l, r, w, sum, ans;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].cnt >> a[i].ch, sum += a[i].cnt;
	sum /= 2;
	l = 1;
	r = n;
	lc = min(sum, a[1].cnt);
	rc = min(sum, a[n].cnt);
	while(1){
		ans += (a[l].ch != a[r].ch) * (min(sum, min(lc, rc)) - w);
		if(lc == rc && rc == sum) break;
		w = min(sum, min(lc, rc));
		if(lc == w && lc < sum) lc = min(lc + a[++l].cnt, sum);
		if(rc == w && rc < sum) rc = min(rc + a[--r].cnt, sum);
	}
	cout << ans << endl;
	return 0;
}
