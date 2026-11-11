#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1.substr(0,2) == s2.substr(0,2)) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1.substr(0,2) == s2.substr(0,2) && (('A' <= s1[s1.size()-1] && s1[s1.size()-1] <= 'C' && 'A' <= s2[s2.size()-1] && s2[s2.size()-1] <= 'C') || ('D' <= s1[s1.size()-1] && s1[s1.size()-1] <= 'F' && 'D' <= s2[s2.size()-1] && s2[s2.size()-1] <= 'F'))){
		cout << 1;
		if ('D' <= s1[s1.size()-1] && s1[s1.size()-1] <= 'F' && 'D' <= s2[s2.size()-1] && s2[s2.size()-1] <= 'F') cout << 1;
		else if (s1[s1.size()-1] == 'A' && s2[s2.size()-1] == 'B') cout << 1;
		else if (s1[s1.size()-1] == 'B' && s2[s2.size()-1] == 'C') cout << 1;
		else if (s1[s1.size()-1] == 'B' && s2[s2.size()-1] == 'A') cout << 1;
		else if (s1[s1.size()-1] == 'C' && s2[s2.size()-1] == 'B') cout << 1;
		else cout << 0;
	}
	else cout << "00";
	return 0;
}
