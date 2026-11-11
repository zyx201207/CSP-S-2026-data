#include <bits/stdc++.h>
using namespace std;

bool f = false, s = false;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);     cout.tie(0);
	
	string a, aa, b, bb;
	cin >> a >> aa >> b >> bb;
	if (aa[2] == 'A' || aa[2] == 'B' || aa[2] == 'C')f = true;
	if (bb[2] == 'A' || bb[2] == 'B' || bb[2] == 'C')s = true;
	
	if (a == b)
		cout << 1;
	else {
		cout << "0000\n";
		return 0;
	}
	
	if (aa[0] == bb[0] && aa[1] == bb[1])
		cout << 1;
	else {
		cout << "000\n";
		return 0;
	}
	
	if (f == s)
		cout << 1;
	else {
		cout << "00\n";
		return 0;
	}
	
	if (f == false && s == false)
		cout << 1;
	else if (aa[2] == 'B' || bb[2] == 'B')
		cout << 1;
	else cout << 0;
	
	return 0;
} 
