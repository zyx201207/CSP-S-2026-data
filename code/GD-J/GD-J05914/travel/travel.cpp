#include <bits/stdc++.h>
using namespace std;

string x1, x2, seat1, seat2;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> x1 >> seat1 >> x2 >> seat2;
	
	//1
	bool flag = true;
	for (int i = 0; i < 2; i ++) {
		if (x1[i] != x2[i])    flag = false;
	}
	cout << ((flag == true) ? 1 : 0);
	
	//2
	for (int i = 0; i < 2; i ++) {
		if (seat1[i] != seat2[i])   flag = false;
	}
	cout << ((flag == true) ? 1 : 0);
	
	//3
	if (flag) {
		if (seat1[2] <= 'C' && seat2[2] <= 'C' && seat1[2] >= 'A' && seat2[2] >= 'A') {
			cout << 1;
		}
		else if (seat1[2] >= 'D' && seat2[2] >= 'D' && seat1[2] <= 'F' && seat2[2] <= 'F') {
			cout << 1;
		}
		else {
			flag = false;
			cout << 0;
		}
	}
	if (flag == false)   cout << 0;
	
	//4
	if (flag == false) {
		cout << 0;
		return 0;
	}
	int diff = abs((int)(seat1[2] - seat2[2]));
	if (diff == 1)  cout << 1;
	else if (diff == 2) {
		if ((seat1[2] == 'D' && seat2[2] == 'F') || (seat1[2] == 'F' && seat2[2] == 'D'))   cout << 1;
		else cout << 0;
	}
	else {
		cout << 0;
	}
	
	return 0;
} 
