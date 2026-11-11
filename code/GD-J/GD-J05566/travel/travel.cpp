#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000"; return 0;
	}
	else cout << "1";
	if (s1.substr(0, 2) != s2.substr(0, 2)){
		cout << "000"; return 0;
	}
	else cout << "1";
	if ((s1 < s2 && s1[2] < 'D' && s2[2] > 'C') || (s1 > s2 && s2[2] < 'D' && s2[2] > 'C')){
		cout << "00"; return 0;
	}
	else cout << "1";
	if (abs(s2[2] - s1[2]) == 1){
		cout << "0"; return 0;
	}
	else cout << "1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
