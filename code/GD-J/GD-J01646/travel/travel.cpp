#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	int hang1 = int(s1[0] - '0') * 10 + int(s1[1] - '0');
	int hang2 = int(s2[0] - '0') * 10 + int(s2[1] - '0');
	char lie1 = s1[2];
	char lie2 = s2[2];
	
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (c1 == c2 && hang1 == hang2) cout << 1;
	else cout << 0;
	if (c1 == c2 && hang1 == hang2 && (lie1 <= 'C' && lie2 <= 'C' || lie1 >= 'D' && lie2 >= 'D') ) cout << 1;
	else cout << 0;
	if (c1 == c2 && hang1 == hang2 && (lie1 <= 'C' && lie2 <= 'C' || lie1 >= 'D' && lie2 >= 'D') && abs( int(lie1) - int(lie2) ) == 1) cout << 1;
	else cout << 0;
	return 0;
}
