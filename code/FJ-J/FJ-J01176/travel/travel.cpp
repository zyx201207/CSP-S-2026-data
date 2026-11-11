#include <bits/stdc++.h>
using namespace std;

string c1, c2, c3, c4;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> c2 >> c3 >> c4; 
	
	if (c1[0] != c3[0] || c1[1] != c3[1]){
		cout << "0000";
	}
	else{
		if (c2[0] != c4[0] || c2[1] != c4[1]){
			cout << "1000";
		}
		else{
			if ((c2[2] == 'C' && c4[2] == 'D') || (c4[2] == 'C' && c2[2] == 'D')){
				cout << "1100";
			}
			else{
				if (c2[2] - '0' == c4[2] - '0' + 1 || c4[2] - '0' == c2[2] - '0' + 1){
					cout << "1111";
				}
				else{
					cout << "1110";
				}
			}
		}
	}
	return 0;
}
