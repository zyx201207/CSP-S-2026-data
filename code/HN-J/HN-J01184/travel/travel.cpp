#include<bits/stdc++.h>

using namespace std;

string c1, c2, s1, s2, a, b;
int flag;
char ct1, ct2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2, flag = (c1 == c2);
	ct1 = s1[s1.size() - 1], ct2 = s2[s2.size() - 1];
	a = s1, s1 = a[0], s1 += a[1];
	b = s2, s2 = b[0], s2 += b[1];
	cout << flag;
	flag &= (s1 == s2);
	cout << flag;
	flag &= !((ct1 <= 'C') ^ (ct2 <= 'C'));
	cout << flag;
	if(ct1 > ct2) swap(ct1, ct2);
	flag &= ((ct2 - ct1) == 1 && ct2 != 'D' && ct2 != 'F') || ((ct2 - ct1) == 2 && ct2 == 'F');
	cout << flag;
	return 0;
}
