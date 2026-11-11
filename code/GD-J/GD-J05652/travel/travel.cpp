#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cc1, cc2;
string ss1, ss2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	if (cc1 == cc2){
		cout << 1;
		if (ss1[0] == ss2[0] && ss1[1] == ss2[1]){
			cout << 1;
			if ((ss1[2] >= 'A' && ss2[2] >= 'A' && ss1[2] <= 'C' && ss2[2] <= 'C')){
				cout << 1;
				if ((ss1[2] == 'A' && ss2[2] == 'C') || (ss1[2] == 'C' && ss2[2] == 'A')){
					cout << 0;
				}else cout << 1;
			}else if ((ss1[2] == 'D' && ss2[2] == 'F') || (ss1[2] == 'F' && ss2[2] == 'D')){
				cout << 1 << 1;
			}else cout << 0 << 0;
		}else cout << 0 << 0 << 0;
	}else cout << 0 << 0 << 0 << 0;
	return 0;
} 
