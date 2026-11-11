#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(#s ".in","r",stdin)
#define out(s) freopen(#s ".out","w",stdout)

string c1,s1,c2,s2;
bool f1,f2,f3,f4;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	in(travel);
	out(travel);
	cin >> c1 >> s1 >> c2 >> s2;
	f1 = c1 == c2;
	f2 = f1 && s1.substr(0,2) == s2.substr(0,2);
	char p1 = s1[2], p2 = s2[2];
	if (('A' <= p1 && p1 <= 'C' && 'A' <= p2 && p2 <= 'C') || ('D' <= p1 && p1 <= 'E' && 'D' <= p2 && p2 <= 'E'))	f3 = f2;
	if (!((p1 == 'A' && p2 == 'C') || (p1 == 'C' && p2 == 'A')))	f4 = f3;
	cout << f1 << f2 << f3 << f4 << endl;
	return 0;
}
