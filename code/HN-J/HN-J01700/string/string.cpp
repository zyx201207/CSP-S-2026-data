#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int x[200005];
	char y[200005];
	long long num = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> x[i] >> y[i];
		num+= x[i];
	}
	long long w = 0;
	for (int i = 0;i < n;i++) {
		if (y[i] == y[0]) {
			w+= x[i];
		}
	
	}
		
		if (num - w == 0) {
			cout << 0;
	}
		else {
			cout << w;
		}
	return 0;  
} 
