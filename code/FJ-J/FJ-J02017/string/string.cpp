#include<iostream>
#include<cstring>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int i, j, sum;
	int n;
	int x, z;
	string S;
	
	sum = 0;
	x = 0;
	z = 0;
	
	cin >> n;
	
	long long a[n + 2];
	char c[n + 2];
	
	for(i = 0; i < n; i ++) {
		cin >> a[i] >> c[i];
		z += a[i];
	}
	
	for(i = 0; i < n; i ++) {
		for(j = 0; j < a[i]; j ++) {
			S[x] = c[i];
			x ++;
		}
	}
	
	z = z - 1;
	
	for(i = 0; i < z; i ++) {
		if(S[i] != S[z]) {
			sum ++;
		}
		z --;
	}
	
	cout << sum;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
