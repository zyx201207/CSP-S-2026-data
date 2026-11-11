#include <bits/stdc++.h> 

using namespace std;

int n;

int main() {
	

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin  >> n;
	int a[n];
	string c[n];

	for (int i = 0; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	
	if(n <= 1) {
		cout << 0;
	} else {
		if (a[0] < a[1]) {
			cout <<a[0];
		} else if(a[1] < a[0]){
			cout << a[1];
		} else {
			cout << 0; 
		}
	}
	 
	
	return 0;
}	
	
	
	
	