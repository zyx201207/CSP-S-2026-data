#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
string s1, c1, s2, c2;
bool b1, b2, b3, b4;
int pr, px;
inline bool tc(char a, char b){			//Í¬²à 
	if(a >= 'A' && a <= 'C'){return (b >= 'A' && b <= 'C');}
	return (b == 'D' || b == 'F');
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2; 
	pr = (s1[0] - '0') * 10 + (s1[1] - '0');
	px = (s2[0] - '0') * 10 + (s2[1] - '0');
	b1 = (c1 == c2);
	b2 = (b1 && pr == px);
	b3 = (b2 && tc(s1[2], s2[2]));
	b4 = (b3 && abs(s1[2] - s2[2]) == 1);
	cout << b1 << b2 << b3 << b4;
	return 0;
}
