#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, l, r, ans, k;
struct node{
	int sum;
	char c;
}a[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i].sum >> a[i].c;
	l = 1;r = n;
	while(l < r){
		k = min(a[l].sum, a[r].sum);
		if(a[l].c != a[r].c){
			ans += k;
		}
		a[l].sum -= k;
		a[r].sum -= k;
		if(a[l].sum == 0) l ++;
		if(a[r].sum == 0) r --;
	}
	cout << ans;
	return 0;
}
