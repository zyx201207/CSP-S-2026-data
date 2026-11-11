#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int f1 = 0,f2 = 0,f3 = 0,f4 = 0;
	if (c1 == c2) f1 = 1;
	if (f1 == 1 and s1[0] == s2[0] and s1[1] == s2[1]) f2 = 1;
	if (f1 == 1 and f2 == 1 and (((s1[2] == 'A' or s1[2] == 'B' or s1[2] == 'C') and (s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C')) or ((s1[2] == 'D' or s1[2] == 'F') and (s2[2] == 'D' or s2[2] == 'F')))) f3 = 1;
	if (f1 == 1 and f2 == 1 and f3 == 1 and ((s1[2] == 'A' and s2[2] == 'B') or (s1[2] == 'B' and (s2[2] == 'A' or s2[2] == 'C')) or (s1[2] == 'C' and s2[2] == 'B') or (s1[2] == 'D' and s2[2] == 'F') or (s1[2] == 'F' and s2[2] == 'D'))) f4 = 1;
	cout << f1 << f2 << f3 << f4; 
	return 0;
}
