//GZ-J00084 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define vec vector
#define str string
#define pll pair<ll, ll>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	str c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool r1 = (c1 == c2);
	bool r2 = (r1 && s1[0] == s2[0] && s1[1] == s2[1]);
	
	if(s1[2] > s2[2]) swap(s1[2], s2[2]);
	bool ck1 = (s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C'));
	bool ck2 = (s1[2] == 'B' && s2[2] == 'C');
	bool ck3 = (s1[2] == 'D' && s2[2] == 'E');
	bool r3 = (r2 && (ck1 || ck2 || ck3));
	
	bool ck4 = (s1[2] == 'A' && s2[2] == 'B');
	bool r4 = (r3 && (ck4 || ck2 || ck3));
	
	cout << (r1 ? 1 : 0);
	cout << (r2 ? 1 : 0);
	cout << (r3 ? 1 : 0);
	cout << (r4 ? 1 : 0);
	
	return 0;
}
