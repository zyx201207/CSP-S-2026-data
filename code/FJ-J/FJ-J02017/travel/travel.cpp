#include<iostream>
#include<cstring>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int i, flag;
	int c1, c2;
	string s1, s2;
	
	flag = 0;
	
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	
	if(c1 == c2) {
		flag ++;
	}
	
	if(flag == 1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		flag ++;
	}
	
	if(flag == 2) {
		if((s1[2] <= 'C' && s1[2] >= 'A') && (s2[2] <= 'C' && s2[2] >= 'A')) {
			flag ++;
		} else if((s1[2] <= 'F' && s1[2] >= 'D') && (s2[2] <= 'F' && s2[2] >= 'D')) {
			flag ++;
		}
	}
	
	if(flag == 3) {
		if(s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2]) {
			flag ++;
		}
	}
	
	for(i = 0; i < 4; i ++) {
		if(flag - 1 >= 0) {
			flag --;
			cout << 1;
		} else {
			cout << 0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
