#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string str = "", temp_str;
	int cnum, num, cnt=0;
	cin >> cnum;
	for (int i=0; i<cnum; i++) {
		cin >> num >> temp_str;
		for (int i=0; i<num; i++) {
			str += temp_str;
		}
	}
	 
	
	for (int i=0; i<(str.size()-1)/2; i++) {
		if (str[i] != str[(str.size()-1)/2]) {
			cnt++;
		}
	}
	
	cout << cnt;
	
	
	return 0;
} 
