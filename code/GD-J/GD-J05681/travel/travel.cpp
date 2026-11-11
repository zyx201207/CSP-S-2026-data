#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	if (c1 == c2) {
		string ls1 = s1.substr(0, 2);
		string ls2 = s2.substr(0, 2);
		if (ls1 == ls2) {
			char c1 = s1[2];
			char c2 = s2[2];
			if (c1 >= 'A' && c1 <= 'C' && c2 >= 'A' && c2 <= 'C') {
				if (abs(c1-c2)!= 1){
					cout << "1110";
					return 0;
				}
			}else if (c1 >= 'D' && c1 <= 'F' && c2 >= 'D' && c2 <= 'F') {
				cout << "1111";
				return 0;
			}else {
				cout << "1100";
				return 0;
			}
		}else {
			cout << "1000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}
	cout << "1111";
	return 0;
} 
