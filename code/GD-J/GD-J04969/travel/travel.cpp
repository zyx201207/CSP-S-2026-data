#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1 != c1){
		cout << "0000";
	}
	else{
		cout << 1;
		if(s2[0] != c2[0] || s2[1] != c2[1]){
			cout << "000";
		}
		else{
			cout << 1;
			int a = s2[2] - 'A',b = c2[2] - 'A';
			if((a <= 2 && b <= 2) || (a > 2 && b > 2)){
				cout << 1;
				if((a - b == 1 || a - b == -1) && ((a != 3 && b != 4) || (a != 4 && b != 3))){
					cout << 1;
				}
				else cout << 0;
			}
			else{
				cout << "00";
			}
		}
	}
	return 0;
} 
