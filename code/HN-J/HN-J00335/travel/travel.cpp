#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	char a = s1[0], b = s1[1], c = s2[0], d = s2[1];
	char n = s1[2], m = s2[2];
	if(c1 != c2) cout << "0000";
	else if(c1 == c2){
		if(a == c && b == d){
			if(((n == 'A' || n == 'B' || n == 'C') && (m == 'A' || m == 'B' || m == 'C'))
			 || ((n == 'D' || n == 'F') && (m == 'D' || m == 'F'))){
				if(((((n == 'A') || (n == 'B')) && ((m == 'A') || (m == 'B')))
				 || (((n == 'B') || (n == 'C')) && ((m == 'B') || (m == 'C')))
				 || (((n == 'D') || (n == 'F')) && ((m == 'D') || (m == 'F')))) && s1 != s2) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	return 0;
}
