#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	string s1, c1, s2, c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if(s1 == s2){
		cout << 1;
		string h1 = c1.substr(0, 2), h2 = c2.substr(0, 2);
		if(h1 == h2){
			cout << 1;
			char l1 = c1[2], l2 = c2[2];
			if(('A' <= l1 && l1 <= 'C') && ('A' <= l2 && l2 <= 'C')){
				cout << 1;
				if(abs(l1 - l2) <= 1) cout << 1;
				else cout << 0;
			}else if((l1 == 'D' || l1 == 'F') && (l2 == 'D' || l2 == 'F')){
				cout << "11";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	return 0;
}
/*
02 01A 02 01B
*/
