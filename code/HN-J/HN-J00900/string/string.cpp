#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, c1, c2;
ll nw = 1, sum, md, ans;
struct node{
	ll x;
	char c;
	ll l, r;
} a[N], b[N], c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].c;
		a[i].l = nw, a[i].r = nw + a[i].x - 1, sum += a[i].x, nw += a[i].x;
	}
	md = sum / 2;
	for(int i = 1; i <= n; i++){
		if(md > a[i].r) b[++c1] = a[i];
		else{
			b[++c1] = {md - a[i].l + 1, a[i].c, a[i].l, md};
			break;
		}
	}
	md = (sum % 2 == 0 ? sum / 2 + 1 : (sum + 1) / 2 + 1);
	for(int i = n; i >= 1; i--){
		if(md < a[i].l) c[++c2] = {a[i].x, a[i].c, sum - a[i].r + 1, sum - a[i].l + 1};
		else{
			c[++c2] = {a[i].r - md + 1, a[i].c, sum - a[i].r + 1, sum - md + 1};
			break;
		}
	}
	int l = 1, l2 = 1;
	while(l <= c1 || l2 <= c2){
		ll mn = min(b[l].x, c[l2].x);
		if(b[l].c != c[l2].c) ans += mn;
		b[l].x -= mn, c[l2].x -= mn;
		if(b[l].x == 0) l++;
		if(c[l2].x == 0) l2++;
	}
	cout << ans;
	return 0;
}
