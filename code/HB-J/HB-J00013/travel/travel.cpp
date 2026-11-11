#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	int c1, s1, c2, s2;
        char x1, x2;
	scanf("%d%d%c%d%d%c", &c1, &s1, &x1, &c2, &s2, &x2);
	int ans1 = (c1 == c2);
	int ans2 = (ans1 && s1 == s2);
	int ans3 = (ans2 && ((x1 == 'A' || x1 == 'B' || x1 == 'C') && (x2 == 'A' || x2 == 'B' || x2 == 'C') || (x1 == 'D' || x1 == 'F') && (x2 == 'D' || x2 == 'F')));
	if (x1 > x2) swap(x1, x2);
	int ans4 = (ans3 && (x1 == 'A' && x2 == 'B' || x1 == 'B' && x2 == 'C' || x1 == 'D' & x2 == 'F'));
	printf("%d%d%d%d\n", ans1, ans2, ans3, ans4);
	return 0;
}
