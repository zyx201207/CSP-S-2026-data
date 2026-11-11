#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		int s_1 = (s1[0]-'0') * 10 + (s1[1]-'0'), s_2 = (s2[0]-'0') * 10 + (s2[1]-'0'), k1 = s1[2] - 'A' + 1, k2 = s2[2] - 'A' + 1;
		if(s_1 == s_2){
			cout << "1";
			if((k1<=3 && k2<=3) || (k1>=4 && k2>=4)){
				cout << "1";
				if(abs(k1-k2) == 1) cout << "1";
				else cout << "0";
			}else cout << "00";
		}else cout << "000";
	} else cout << "0000";
	return 0;
}
