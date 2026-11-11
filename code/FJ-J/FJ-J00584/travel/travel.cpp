// gufen:0~100
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int g1 = (s1[0] - '0') * 10 + s1[1] - '0';
	int g2 = (s2[0] - '0') * 10 + s2[1] - '0';
	char k1 = s1[2], k2 = s2[2];
	if(k1 > k2) swap(k1, k2);
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	else{
		cout << "1";
		if(g1 != g2){
			cout << "000"; 
			return 0;
		}
		else{
			cout << 1;
			if(k1 <= 'C' && k2 >= 'D'){
				cout << "00";
				return 0;
			}
			else{
				cout << 1;
				if((k1 == 'A' && k2 == 'B') || (k1 == 'B' && k2 == 'C') || (k1 == 'D' && k2 == 'F')){
					cout << 1;
					return 0;
				}
				else cout << 0;
			}
		}
	}
	return 0;
}
// Accepted at : 8:44
//  ÆÀ¼¶ £ºred+ / orange- 
