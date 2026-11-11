#include<bits/stdc++.h>
#define f(i, s, e) for(int i = s; i <= e; ++i)
#define dw(i, e, s) for(int i = e; i >= s; --i)
#define int long long
#define pii pair<int, int>
using namespace std; 

int n, a[200005], ans;
char ch[200005];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	f(i, 1, n) cin >> a[i] >> ch[i];
	int p = 1, q = n, tp = a[1], tq = a[n];
	while(p < q){
		if(ch[p] != ch[q]) ans += min(tp, tq);
		if(tp < tq) tq -= tp, tp = a[++p];
		else if(tp == tq) tp = a[++p], tq = a[--q];
		else tp -= tq, tq = a[--q];
	}
	cout << ans;
	return 0;
}
