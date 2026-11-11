#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1,s2,x1,x2;
	cin >> s1 >> s2 >> x1 >> x2;
	if (s1 != x1){
		cout << "0000";
	}else {
		cout << '1';
		if (s2[0] - '0' != x2[0] - '0'|| s2[1] - '0' != x2[1] - '0'){
			cout << "000";
		}
		else {
			cout << '1';
			if (! ((s2[2] <= 'C' && x2[2] <= 'C') || (s2[2] > 'C' && x2[2] > 'C'))){
				cout << "00";
			}
			else {
				cout << '1';
				if (abs(s2[2] - x2[2]) == 1 || s2[2] == 'F' && x2[2] == 'D' || s2[2] == 'D' && x2[2] == 'F'){
					cout << '1';
				}
				else cout << '0';
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
