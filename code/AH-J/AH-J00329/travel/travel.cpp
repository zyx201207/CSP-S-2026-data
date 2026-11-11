#include<bits/stdc++.h>
using namespace std;
int c1, c2, r1, r2;
bool f1, f2, f3, f4;
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	r1 = (s1[0] - '0') * 10 + (s1[1] - '0'), r2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	f1 = (c1 == c2);
	f2 = f1 && (r1 == r2);
	f3 = f2 && ((s1[2] >= 'A' && s1[2] <= 'C') == (s2[2] >= 'A' && s2[2] <= 'C'));
	f4 = f3 && (r1 == r2 && abs(s2[2] - s1[2]) == 1);
	cout << f1 << f2 << f3 << f4;
	return 0;
}
