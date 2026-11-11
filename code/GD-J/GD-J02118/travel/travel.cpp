#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, M = 5e5 + 5;
string c1, s1, c2, s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << "1";
	for(int i = 0;i < 2;i++){
		if(s1[i] != s2[i]){
			cout << "000";
			return 0;
		}
	}
	cout << "1";
	char s12 = s1[2], s22 = s2[2];
	if((s12 >= 'A' && s12 <= 'C' && s22 >= 'A' && s22 <= 'C') || (s12 >= 'D' && s12 <= 'F' && s22 >= 'D' && s22 <= 'F')){
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if(s12 == 'A' && s22 == 'B' || s12 == 'B' && s22 == 'A' || s12 == 'B' && s22 == 'C' || s12 == 'C' && s22 == 'B' || s12 == 'D' && s22 == 'F' || s12 == 'F' && s22 == 'D'){
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
