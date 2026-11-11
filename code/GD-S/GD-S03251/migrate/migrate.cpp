#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l, r;
}b[2000005], c[2000005];
int id, t, n, d, a[2000005], cnt, ans, len, h;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> id >> t;
	while(t--){
		cnt = len = ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			if(!(i > 1 && a[i] - a[i - 1] <= d))c[len].r = i - 1, c[++len].l = i;
		}
		c[len].r = n;
		for(int i = 1;i <= n - 3;i++)
			if(a[i + 2] - a[i] <= d && a[i + 3] - a[i + 1] <= d && a[i + 3] - a[i] > d)b[++cnt].l = i, b[cnt].r = i + 3;
		h = 1;
		for(int i = 1;i <= len;i++){
			if(b[h].r <= c[i].r && b[h + 1].r <= c[i].r && h + 1 <= cnt)ans += (b[h].l - c[i].l + 1) * (b[h + 1].l + 2 - b[h].r + 1);
			else ans += (b[h].l - c[i].l + 1) * (c[i].r - b[h].r + 1);
			h++;
			if(h > cnt)break;
			while(c[i].l <= b[h].l && b[h].r <= c[i].r && c[i].l <= b[h + 1].l && b[h + 1].r <= c[i].r && h + 1 <= cnt) 
				ans += (b[h].l - b[h - 1].r + 3) * (b[h + 1].l + 2 - b[h].r + 1), h++;
			if(b[h].r <= c[i].r && (b[h + 1].r > c[i].r || h == cnt)) ans += (b[h].l - b[h - 1].r + 3) * (c[i].r - b[h].r + 1);
			h++;
			if(h > cnt)break;
		}
		cout << ans << '\n';
	}
	return 0;
}
