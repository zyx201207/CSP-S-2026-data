#include<bits/stdc++.h>
#define f(i, s, e) for(int i = s; i <= e; ++i)
#define dw(i, e, s) for(int i = e; i >= s; --i)
#define int long long
#define pii pair<int, int>
using namespace std;

int n, m, a[500005], nxt[500005], pre[300005], nxt2[500005], lst, dif[500005], c[300005];

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	f(i, 1, n) cin >> a[i];
	dw(i, n, 1){
		nxt[i] = pre[a[i]];
		nxt2[i] = lst;
		if(nxt[i]) lst = i;
		if(!pre[a[i]]) pre[a[i]] = i;
	}
	f(i, 1, n){
		int j = i;
		while(1){
			if(nxt[j])
				j = nxt[j];
			++dif[j];
			if(!nxt2[j]) break;
			--dif[(j = nxt2[j])];
		}
	}
	f(i, 1, n) dif[i] += dif[i - 1], c[a[i]] += dif[i];
	f(i, 1, m) cout << c[i] << " ";
	return 0;
}
