#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int k1, k2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	k1 = (s1[0]-'0')*10 + s1[1]-'0';
	k2 = (s2[0]-'0')*10 + s2[1]-'0';
	bool a1 = (c1 == c2);
	bool a2 = (k1 == k2);
	bool a3 = ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'));
	bool a4 = (abs(s1[2]-s2[2]) == 1);
	cout << (a1 ? 1 : 0);
	cout << (a1&&a2 ? 1 : 0);
	cout << (a1&&a2&&a3 ? 1 : 0);
	cout << (a1&&a2&&a3&&a4 ? 1 : 0);
	return 0;
}
