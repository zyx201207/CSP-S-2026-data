#include <iostream>
#include <cstdio>
using namespace std;
void speedup()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	speedup();
	int c1, s1, c3, s3;
	char c2, s2;
	cin >> c1 >> c3 >> c2 >> s1 >> s3 >> s2;
	if (c1 == s1) cout << 1; else cout << 0;
	if (c1 == s1 && c3 == s3) cout << 1; else cout << 0;
	if (c1 == s1 && c3 == s3 && ((c2 <= 'C' && s2 <= 'C') || (c2 >= 'D' && s2 >= 'D'))) cout << 1; else cout << 0;
	if (c1 == s1 && c3 == s3 && ((c2 <= 'C' && s2 <= 'C') || (c2 >= 'D' && s2 >= 'D')) && abs(c2 - s2) == 1) cout << 1; else cout << 0;
	return 0;
}
