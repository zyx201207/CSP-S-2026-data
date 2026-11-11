#include<bits/stdc++.h>
using namespace std;
string c, s, c2, s2;
bool flag = true;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> c2 >> s2;
	if((c == c2 && c != "01") && c != "16")
		cout << '1';
	else{
		cout << '0';
		flag = false;
	}
	if((s[0] == s2[0] && s[1] == s2[1]) && flag)
		cout << '1';
	else{
		cout << '0';
		flag = false;
	}
	if((((s[2] == 'A' || s[2] == 'B' || s[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s[2] == 'D' || s[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))) && flag)
		cout << '1';
	else
		cout << '0';
	if((((s[2] == 'A' && s2[2] == 'B') || (s2[2] == 'A' && s[2] == 'B')) || ((s[2] == 'B' && s2[2] == 'C') || (s2[2] == 'B' && s[2] == 'C')) || ((s[2] == 'D' && s2[2] == 'F') || (s2[2] == 'F' && s[2] == 'D'))) && flag)
		cout << '1';
	else
		cout << '0';
	return 0;
}
