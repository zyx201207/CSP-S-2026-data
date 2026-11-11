#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool a, b, c = 1, d;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		a = 1;
	if (a && s1[0] == s2[0] && s1[1] == s2[1])
		b = 1;
	if (!a || !b || (s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C'))
		c = 0;
	if (a && b && c && (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2] || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')))
		d = 1;
	cout << a << b << c << d;
	return 0;
}

