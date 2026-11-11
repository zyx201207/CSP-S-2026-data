#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << "0000" << endl;
		return 0;
	}
	if(s1[0] == s2[0] and s1[1] == s2[1]){
		cout << 1;
	}else{
		cout << "000" << endl;
		return 0;
	}
	if(s1[2] >= 'A' and s1[2] <= 'C'){
		if(s2[2] >= 'A' and s2[2] <= 'C'){
			cout << 1;
		}else{
			cout << "00" << endl;
			return 0;
		}
	}else{
		if(s2[2] >= 'A' and s2[2] <= 'C'){
			cout << "00" << endl;
			return 0;
		}else{
			cout << 1;
		}
	}
	if(s1[2] - 'A' + 1 == s2[2] - 'A' or s1[2] - 'A' - 1 == s2[2] - 'A'){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
