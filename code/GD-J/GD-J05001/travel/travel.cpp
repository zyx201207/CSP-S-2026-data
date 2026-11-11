# include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << "0000";
		return 0;
	}
	if (s1.substr(0, 2) != s2.substr(0, 2)){
		cout << "1000";
		return 0;
	}
	if (('A' <= s1[2] && s1[2] <= 'C') && ('D' <= s2[2] && s2[2] <= 'E')){
		cout << "1100";
		return 0;
	}
	if (('A' <= s2[2] && s2[2] <= 'C') && ('D' <= s1[2] && s1[2] <= 'E')){
		cout << "1100";
		return 0;
	}
	if (s1[2] + 1 != s2[2] && s1[2] != s2[2] + 1){
		cout << "1110";
		return 0;
	}
	cout << "1111";
}

