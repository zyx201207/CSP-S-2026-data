#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int p1, p2;
	p1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(c1 == c2)cout << 1;
	else cout << 0;
	if(c1 == c2 && p1 == p2)cout << 1;
	else cout << 0;
	if(c1 == c2 && p1 == p2 && ((s1[2] <= 'C' && s2[2] <= 'C' ) || s1[2] >= 'D' && s2[2] >= 'D'))cout << 1;
	else cout << 0;
	if(c1 == c2 && p1 == p2 && ((s1[2] <= 'C' && s2[2] <= 'C' ) || s1[2] >= 'D' && s2[2] >= 'D')){
		if(s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1 || (s1[2] >= 'D' && s2[2] >= 'D'))cout << 1;
		else cout << 0;
	}else cout << 0;
	return 0;
}
