#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char a = s1[2], b = s2[2];
	if(c1 == c2)cout << 1;
	else cout << 0;
	if(s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2){
		cout << 1;
		if('A' <= a && a <= 'C' && 'A' <= b && b <= 'C' || a == 'D' && b == 'F' || a == 'F' && b == 'D' || a == b)cout << 1;
		else cout << 0;
		if('A' <= a && a <= 'C' && 'A' <= b && b <= 'C'){
		if(abs(a - b) <= 1)cout << 1;
		else cout << 0;
		}else{
		if(a == 'D' && b == 'F' || a == 'F' && b == 'D')cout << 1;
		else cout << 0;
	}
	}else{
		cout << "000";
	}
	return 0;
} 
