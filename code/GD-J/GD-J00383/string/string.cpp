#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char a[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin >> t;
	int sum = 0;
	int i = 1;
	while (t--) {
		int s;
		char c;
		cin >> s >> c;
		sum += s;
		for (;i <= sum;i++) {
			a[i] = c;
		}
		//sum += s;
	}
	//for (int i = 1;i <= sum;i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	int l = 1,r = sum;
	int res = 0;
	//cout << 25723;
	while (l <= r) {
		//cout << a[l] << " " << a[r] << endl;
		if (a[l] != a[r]) {
			//cout << a[l] << " " << a[r] << endl;
			res++;
			l++,r--;
		}
		else {
			l++,r--;
		}
	}
	cout << res;
}
