#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		string a = "";
		a = a + s1[0] + s1[1];
		string b = "";
		b = b + s2[0] + s2[1];
		if(a == b){
			cout << 1;
			char c = s1[2];
			char d = s2[2];
			int k = 0;
			if((c == 'A' || c == 'B' || c == 'C') && (d == 'A' || d == 'B' || d == 'C') && c != d){
				k = 1;
			}else if((c == 'D' || c == 'F') && (d == 'D' || d == 'F') && c != d){
				k = 2;
			}
			if(k != 0){
				if(k == 1){
					cout << 1;
					if(abs(c-d) == 1){
						cout << 1;
					}else{
						cout << 0;
					}
				}else if(k == 2){
					cout << 11;
				}
			}else{
				cout << 0 << 0;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
}
	return 0;
}
