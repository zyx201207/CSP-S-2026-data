#include <bits/stdc++.h>
#define int long long
using namespace std;

char c1e,c1f;
string c1a,c1b,c1c,c1d,s;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1a >> s;
	c1b = s[0];
	c1b += s[1];
	c1e = s[2];
	cin >> c1c >> s;
	c1d = s[0];
	c1d += s[1];
	c1f = s[2];
	cout << (c1a == c1c);
	cout << ((c1a == c1c) && (c1b == c1d));
	cout << ((c1a == c1c) && (c1b == c1d) && 
	!(
		(((c1e == 'A') || (c1e == 'B') || (c1e == 'C')) && ((c1f == 'D') || (c1f == 'F'))) || 
		(((c1f == 'A') || (c1f == 'B') || (c1f == 'C')) && ((c1e == 'D') || (c1e == 'F')))
	));
	cout << ((c1a == c1c) && (c1b == c1d) && 
	(
		(c1e == 'A' && c1f == 'B') || 
		(c1f == 'A' && c1e == 'B') || 
		(c1e == 'B' && c1f == 'C') || 
		(c1f == 'B' && c1e == 'C') || 
		(c1e == 'D' && c1f == 'F') || 
		(c1f == 'D' && c1e == 'F')
	));
	return 0;
}
