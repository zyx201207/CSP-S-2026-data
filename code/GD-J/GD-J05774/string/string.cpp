#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long n;
	cin >> n;
	string sss; 
	for (long long i = 1; i <= n; i++) {
		long long a;
		char aa;
		cin >> a >> aa;
		
		while (a--) {
			sss += aa;
		}
	}
//	cout << sss << endl;
	long long tot = 0;
	long long s = sss.size();
	long long ss = s / 2;
	for (int i = 0; i < ss; i++) {
//		cout << i << " " << sss[i] << " " << sss[s - i - 1] << endl;
		if (sss[i] != sss[s - i - 1]) tot++;
	}
	cout << tot << endl;
	
	return 0;
}

// 6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
