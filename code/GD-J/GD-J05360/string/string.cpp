#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 2e5 + 10;
struct node{
	ll l, r;
	char v;
}a[MAX];
int n;
ll len, ans, mid, ml;
int find_pos(ll x){
	if (x >= (len + 1) / 2){
		for (int i = mid + 1; i <= n; i++)
			if (a[i].l <= x && a[i].r >= x) return i;
	}
	else{
		for (int i = 1; i <= mid; i++)
			if (a[i].l <= x && a[i].r >= x) return i;
	}
}
void get_ans(int pos, ll plen){
	if (pos > mid) return ;
	int r_pos = find_pos(len - plen);
	if (r_pos < mid || r_pos > len) return ;
	ll rl = len - a[r_pos].r + 1, rr = rl + a[r_pos].r - a[r_pos].l + 1;
	if (a[pos].l <= rl && a[pos].r >= rr){
		if (a[pos].v != a[r_pos].v){
			ans += a[r_pos].r - a[r_pos].l + 1;
		}
		if (a[pos].v != a[r_pos - 1].v){
			ans += a[pos].r - rr + 1;
		}
		if (a[r_pos].r != len && a[r_pos + 1].v != a[pos].v){
			ans += rl - a[pos].l + 1;
		}
	} 
	else if (a[pos].l >= rl && a[pos].r <= rr)
		if (a[pos].v != a[r_pos].v) ans += a[pos].r - a[pos].l + 1;
	else if (a[pos].l <= rl && a[pos].r <= rr){
		if (a[pos].v != a[r_pos].v) ans += a[pos].r - rl + 1;
		if (a[r_pos].r != len && a[r_pos + 1].v != a[pos].v) ans += rl - a[pos].l + 1;
	}
	else{
		if (a[pos].v != a[r_pos].v) ans += rr - a[pos].l + 1;
		if (a[r_pos - 1].v != a[pos].v) ans += a[pos].r - rr + 1;
	}
	get_ans(pos + 1, plen + a[pos].r - a[pos].l + 1);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0); 
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s;
	for (int i = 1, x; i <= n; i++){
		char c;
		cin >> x >> c;
		a[i].v = c;
		a[i].l = len + 1;
		a[i].r = a[i].l + x - 1;
		len += x;
	}
	ml = (len + 1) / 2;
	// 获取中间区间
	ll tmp = 0;
	for (int i = 1; i <= n; i++){
		tmp += a[i].r - a[i].l + 1;
		if (tmp >= (len + 1) / 2){
			mid = i;
			break;
		}
	}
	get_ans(1, 0);
	cout << ans;
	return 0;
}
