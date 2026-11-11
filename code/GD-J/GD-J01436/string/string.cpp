#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
struct xx {
	ll l, r;
	char c;
};
ll n, sum;
ll m[N];
char x[N];
vector<xx> a, b;
bool cmp (xx A, xx B) {
	return A.l < B.l;
}
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout); 
	cin >> n;
	ll id = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> m[i] >> x[i];
		sum += m[i];
	}
	for (int i = 1; i <= n; i ++) {
		if (id + m[i]- 1 <= (sum + 1) / 2) {
			a.push_back ({id, m[i] + id -1, x[i]});
			//cout << "#1 " << id << ' ' << m[i] + id - 1 << ' ' << x[i] << '\n';
		}
		else if (id <= (sum + 1) / 2) {
			a.push_back ({id, (sum + 1) / 2, x[i]});
			if (sum % 2) b.push_back ({sum - id - m[i] + 2, (sum + 1) / 2, x[i]});
			else b.push_back ({sum - id - m[i] + 2, sum / 2, x[i]});
		}
		else  {
			b.push_back ({sum + 2 - (id + m[i]), sum + 1 - id, x[i]});
		}
		id = id + m[i];
	}
	sort (a.begin (), a.end (), cmp);
	sort (b.begin (), b.end (), cmp);
	//cout << '\n';
	//for (int i = 0; i < a.size (); i ++) cout << a[i].l << ' ' << a[i].r << '\n';
	//cout << '\n';
	//for (int i = 0; i < b.size () ; i ++) cout << b[i].l << ' ' << b[i].r << '\n'; 
	//cout << '\n';
	int ia = 0, ib = 0;
	ll ans = 0;
	for (; ia < a.size ();) {
		while (ib < b.size () && b[ib].l <= a[ia].r) {
			//cout << ia << ' ' << ib << '\n';
			//cout << a[ia].c << ' ' << b[ib].c << '\n';
			if (a[ia].c != b[ib].c) ans += (1 + min (a[ia].r, b[ib].r) - max (a[ia].l, b[ib].l));
			if (a[ia].r == b[ib].r) {
				ia ++;
				ib ++;
			}
			else if (a[ia].r > b[ib].r) ib ++;
			else ia ++;
		}
	} 
	cout << ans;
	return 0; 
}
/*
test 1:

3
2 a
2 b
1 c


test 2:

2
2 a
3 a


test 3:

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


test 7:

6
10 a
10 a
10 a
10 b
10 b
10 b
 
 
test 8:

3
10 a
20 b
10 a
 
 
test 9:

3
10 a
11 b
10 a
*/

// 对的你发现我在造数据
// 懒得算了面向答案编程（吗？）一下就好了 
