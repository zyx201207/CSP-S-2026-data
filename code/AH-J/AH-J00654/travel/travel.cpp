#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2);
	cout << ((c1 == c2) && (s1.substr(0,2) == s2.substr(0,2)));
	cout << ((c1 == c2) && (s1.substr(0,2) == s2.substr(0,2)) && ((('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C')) || (s1[2] == 'C' && s2[2] == 'F')));
	cout << ((c1 == c2) && (s1.substr(0,2) == s2.substr(0,2)) && ((('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C')) || (s1[2] == 'C' && s2[2] == 'F')) && (abs(s1[2] - s2[2]) == 1 || (s1[2] == 'C' && s2[2] == 'F')));
	return 0;
}
