#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
bool check(string s1, string s2){
	if(s1[1] == s2[1] && s1[0] == s2[0]) return true;
	return false;
}
bool check2(string a, string b){
	char c = a[2], d = b[2];
	if((c == 'A' && d == 'B') || (c == 'B' && d == 'C') || (c == 'D' && d == 'F')) return true;
	if((c == 'B' && d == 'A') || (c == 'C' && d == 'B') || (c == 'F' && d == 'D')) return true;
	return false;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(check(c1, c2)) cout << 1;
	else cout << 0;
	if(check(c1, c2) && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	if(check(c1, c2) && s1[0] == s2[0] && s1[1] == s2[1] && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))) cout << 1;
	else cout << 0;
	if(check(c1, c2) && s1[0] == s2[0] && s1[1] == s2[1] && check2(s1, s2)) cout << 1;
	else cout << 0;
	return 0;
}
