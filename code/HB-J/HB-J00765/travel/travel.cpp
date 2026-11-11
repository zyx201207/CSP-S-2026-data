#include  <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int maxn = 2e5 + 10;
const int inf = INT_MAX / 2;

struct Ticket {
    string c, s;
}R, X;

bool ans[5] = {0, 0, 0, 0, 0};

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);

    cin >> R.c >> R.s >> X.c >> X.s;
    //P1
    if (R.c == X.c) cout << 1, ans[1] = 1;
    else cout << 0, ans[1] = 0;
	
	//P2
	if (ans[1] && (R.s[0] == X.s[0]) && (R.s[1] == X.s[1])) cout << 1, ans[2] = 1;
	else cout << 0, ans[2] = 0;
	
	//P3
	////全左
	if (ans[2] && (R.s[2] >= 'A' && R.s[2] <= 'C') && (X.s[2] >= 'A' && X.s[2] <= 'C')) cout << 1, ans[3] = 1;
	////全右
	else if (ans[2] && (R.s[2] >= 'D' && R.s[2] <= 'F') && (X.s[2] >= 'D' && X.s[2] <= 'F')) cout << 1, ans[3] = 1;
	////两边
	else cout << 0, ans[3] = 0;
	
	//P4
	if (ans[3] && abs(R.s[2] - X.s[2]) <= 1) cout << 1;
	else cout << 0;
	
	return 0;
}
