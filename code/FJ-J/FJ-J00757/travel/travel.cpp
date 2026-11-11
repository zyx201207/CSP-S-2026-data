#include<bits/stdc++.h>
using namespace std;
string s1, s2, t1, t2;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s1 >> s2 >> t1 >> t2;
	bool f1=0, f2=0, f3=0, f4=0;
	if (s1 == t1) f1 = 1;
	if (f1 && s2.substr(0,2) == t2.substr(0,2))
		f2 = 1;
	if (f2 && ((s2[2] <= 'C' && t2[2] <= 'C') || (s2[2] >= 'D' && t2[2] >= 'D')))
		f3 = 1;
	if (f3 && !((s2[2] == 'A' && t2[2] == 'C') || (s2[2] == 'C' && t2[2] == 'A')))
		f4 = 1;
	cout << f1 << f2 << f3 << f4 << "\n";
	return 0;	
}
