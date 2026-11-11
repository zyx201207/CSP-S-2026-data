#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
string s11, s21;
char s12, s22;

int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else cout << 0;
	for (int i = 0; i < s1.size () - 1; i++)
		s11 += s1[i];
	for (int i = 0; i < s2.size () - 1; i++)
		s21 += s2[i];
	if (c1 == c2 && s11 == s21) cout << 1;
	else cout << 0;
	s12 = s1[s1.size () - 1];
	s22 = s2[s2.size () - 1];
	if (c1 == c2 && s11 == s21 && ((s12 >= 'A' && s22 >= 'A' && s12 <= 'C' && s22 <= 'C') 
		|| (s12 >= 'D' && s22 >= 'D' && s12 <= 'E' && s22 <= 'E'))) cout << 1;
	else cout << 0;
	if (c1 == c2 && s11 == s21 && (s12 + 1 == s22 || s12 - 1 == s22) 
		&& !((s12 == 'D' && s22 == 'C') || (s22 == 'D' && s12 == 'C'))) cout << 1;
	else cout << 0;
	return 0;
}
