#include <bits/stdc++.h>
using namespace std;
int c1, c2, s1, s2;
char p1, p2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> p1 >> c2 >> s2 >> p2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1 == s2) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1 == s2 && ((p1 - 'A' <= 2 && p2 - 'A' <= 2) || (p1 - 'A' >= 3 && p2 - 'A' >= 3))) cout << 1;
	else cout << 0;
	if(c1 == c2 && s1 == s2 && ((p1 - 'A' <= 2 && p2 - 'A' <= 2 && abs(p1 - p2) <= 1) || (p1 - 'A' >= 3 && p2 - 'A' >= 3))) cout << 1;
	else cout << 0;
	return 0;
} 
