#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1, c1, s2, c2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[1] != c2[1]){
		cout << "0000";
		return 0;
	}
	if(s1[1] != s2[1]){
		cout << "1000";
		return 0;
	}
	if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
		if(s1[2] + 1 == s2[2]||s2[2] + 1 == s1[2]){
			cout << "1111";

		}else{
			cout << "1110";
		}
		return 0;
	}else if(s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'){
		cout << "1111";
		return 0;
	}
	cout << "1100";
	return 0;
}
