#include <bits/stdc++.h>
using namespace std;
int c1, c2, s1, s2, ans[55];
char t1, t2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> t1 >> c2 >> s2 >> t2;
	if (c1 == c2) ans[1] = 1;
	if (c1 == c2 && s1 == s2) ans[2] = 1;
	if (c1 == c2 && s1 == s2 && (((int)t1 <= 67 && (int)t2 <= 67) || ((int)t1 > 67 && (int)t2 > 67))) ans[3] = 1;
	if (c1 == c2 && s1 == s2 && (abs((int)t1 - (int)t2) == 1 && !(t1 == 'C' && t2 == 'D') && !(t1 == 'D' && t2 == 'C'))) ans[4] = 1;
	cout << ans[1] << ans[2] << ans[3] << ans[4];
	return 0;
}
