#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool tc = false, tp = false, tx = false;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		tx = true;
	}else{
		cout << 0;
	}
	if (tx && (s1[0] == s2[0] && s1[1] == s2[1])){
		tp = true;
		cout << 1;
	}else{
		cout << 0;
	}
	if (tp && (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D')){
		cout << 1;
		tc = true;
	}else{
		cout << 0;
	}
	if (tc && (s1[2] >= 'D' && s2[2] >= 'D' || (int(s1[2] - s2[2] == 1) || int(s1[2] - s2[2] == -1)))){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
} 
