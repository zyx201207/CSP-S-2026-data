#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c1, c2, p1, p2;
char l1, l2;
string s1, s2;
bool f[5];
bool check()
{
	if(l1 < 'D' && l2 > 'C') return false;
	if(l1 > 'C' && l2 < 'D') return false;
	return true;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	p1 = (s1[0] - '0') * 10 + s1[1] - '0';
	p2 = (s2[0] - '0') * 10 + s2[1] - '0';
	l1 = s1[2], l2 = s2[2];
	if(c1 == c2) cout << 1;
	else{
		cout << "0000\n";
		return 0;
	}
	if(p1 == p2) cout << 1;
	else{
		cout << "000\n";
		return 0;
	}
	if(check()) cout << 1;
	else{
		cout << "00\n";
		return 0;
	}
	if(abs((int)l1 - l2) == 1) cout << 1;
	else cout << "0\n";
	return 0;
} 
