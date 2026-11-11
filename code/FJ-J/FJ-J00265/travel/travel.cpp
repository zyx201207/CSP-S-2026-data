 #include <bits/stdc++.h>
 using namespace std;
 string c1, s1, c2, s2;
 int main()
 {
 	freopen("travel.in", "r", stdin);
 	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "";
	if (c1 == c2) ans = "1"; else { cout << "0000\n"; return 0; }
	if (s1[0] == s2[0] && s1[1] == s2[1]) ans += "1"; else { ans += "000"; cout << ans << '\n'; return 0; }
	int a = s1[2] - 'A', b = s2[2] - 'A';
	if (a < 3 && b < 3 || a > 2 && b > 2) ans += "1"; else ans += "0";
	if (a > b) a ^= b, b ^= a, a ^= b;
	if (b - a == 1 && (a != 2 && b != 3)) ans += "1"; else ans += "0";
	cout << ans << '\n';
 	return 0;
 }
