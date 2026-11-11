#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], pre[200005], nxt[200005], ans;
char ch[200005];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for( int i = 1; i <= n; i++ ) cin >> a[i] >> ch[i];
	int pos = n;
	for( int i = 1; i <= n; i++ ) pre[i] = pre[i - 1] + a[i];
	for( int i = n; i >= 1; i-- ) nxt[i] = nxt[i + 1] + a[i];
	for( int i = 1; i <= n; i++ ){
		while(pos && nxt[pos] <= pre[i]){
			int len = nxt[pos] - max(nxt[pos + 1], pre[i - 1]);
			if(ch[i] != ch[pos]) ans += len;
			pos--;
		}
		if(pos){
			int len = pre[i] - max(nxt[pos + 1], pre[i - 1]);
			if(ch[i] != ch[pos]) ans += len;
		}
	}
	cout << (ans >> 1);
	return 0;
}
