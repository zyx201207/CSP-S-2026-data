#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10;
char a[MAX_N], b[MAX_N];
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 5; i++) {
    	cin >> a[i];
    }
    for (int i = 1; i <= 5; i++) {
    	cin >> b[i];
    }
    if (a[1] == b[1] && a[2] == b[2]) {
    	cout << "1";
    	if (a[3] == b[3] && a[4] == b[4]) {
    		cout << "1";
    		if (a[5] >= 'A' && a[5] <= 'C' && b[5] >= 'A' && b[5] <= 'C') {
    			cout << "1";
    			if (a[5] > b[5]) {
    				if (int(a[5] - b[5]) == 1) {
    					cout << "1";
	   				} else {
	   					cout << "0";
	   				}
    			} else if (a[5] < b[5]) {
    				if (int(b[5] - a[5]) == 1) {
    					cout << "1";
    				} else {
    					cout << "0";
    				}
    			}
    		} else if (a[5] >='D'&&b[5] >= 'D'&&a[5] <= 'F'&&b[5] <='F') {
    			cout << "1";
    			if (a[5] == 'D' && b[5] == 'F' || a[5] == 'F' && b[5] == 'D') {
    				cout << "1";
    			} else {
    				cout << "0";
    			}
    		} else {
    			cout << "00";
    		}
    	} else {
    		cout << "000";
    	}
    } else if (a[1] != b[1] || a[2] != b[2]) {
    	cout << "0000";
    }
    return 0;
}
