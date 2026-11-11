#include <bits/stdc++.h>
using namespace std;

string a,b,c,d;
int p;

int main()
{
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if (b[2] == 'D') b[2] = 'E';
	if (d[2] == 'D') d[2] = 'E';
	
	if (a == c) cout << 1;
	else cout << 0;
	
	if (a == c && b[0] == d[0] && b[1] == d[1]) cout << 1;
	else cout << 0;
	
	if (b[2] >= 'E' && d[2] >= 'E') p = 1;
	if (b[2] < 'E' && d[2] < 'E') p = 2;
	
	if (a == c && b[0] == d[0] && b[1] == d[1] && p > 0) cout << 1;
	else cout << 0;
	
	if (p == 2 && abs(d[2] - b[2]) == 1) p = 1;
	
	if (a == c && b[0] == d[0] && b[1] == d[1] && (p == 1)) cout << 1;
	else cout << 0;
	return 0;
}
