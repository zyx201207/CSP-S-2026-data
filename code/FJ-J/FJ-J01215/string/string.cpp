#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 5;
ll n, ans;
struct node {ll l, r; char c;} s[2 * N];
bool cmp(node x, node y) {return x.l < y.l;}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++) { 
		cin >> s[i].r >> s[i].c;
		s[i].l = s[i - 1].r + 1;
		s[i].r += s[i - 1].r;
	}
	ll l = 1, r = n, lenl, lenr, cnt = n;
	while(l < r) {
		lenl = s[l].r - s[l].l + 1;
		lenr = s[r].r - s[r].l + 1;
		if(lenl < lenr) {
			s[++cnt].l = s[r].l + (lenr - lenl);
			s[cnt].r = s[r].r;
			s[r].r = s[cnt].l - 1;
			s[cnt].c = s[r].c;
			l++;
		} else if(lenr < lenl) {
			s[++cnt].r = s[l].r - (lenl - lenr);
			s[cnt].l = s[l].l;
			s[l].l = s[cnt].r + 1;
			s[cnt].c = s[l].c;
			r--;
		} else l++, r--;
	}
	sort(s + 1, s + cnt + 1, cmp);
	for(int i = 1; i <= cnt / 2; i++) 
		if(s[i].c != s[cnt - i + 1].c) ans += s[i].r - s[i].l + 1;
	cout << ans;
	return 0; 
}
