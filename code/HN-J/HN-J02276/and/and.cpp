#include <bits/stdc++.h>
#include <vector>
using namespace std;

int f2(vector<int> v) {
	int l = v.size();
	int res = 0, temp;
	for (int i = 0; i < l; i++) {
		for (int j = i+1; j < l; j++) {
			temp = v[i] & v[j];
			if (temp > res) res = temp;
		}
	}
	return res;
}

//int f3(vector<int> v) {
//	int len = v.size();
//	int res = 0, temp;
//	for (int i = 0; i < len; i++) {
//		for (int j = i+1; j < len; j++) {
//			for (int k = j+1; k < len; k++) {
//				temp = v[i] & v[j] & v[k];
//				if (temp > res) res = temp;
//			}
//		}
//	}
//	return res;
//}

int f4(vector<int> v) {
	int len = v.size();
	int res = 0, temp;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			for (int k = j+1; k < len; k++) {
				for (int l = k+1; l < len; l++) {
				temp = v[i] & v[j] & v[k];
				if (temp > res) res = temp;}
			}
		}
	}
	return res;
}

int f5(vector<int> v) {
	int len = v.size();
	int res = 0, temp;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			for (int k = j+1; k < len; k++) {
				for (int l = k+1; l < len; l++) {
					for (int m = l+1; m < len; m++) {
				temp = v[i] & v[j] & v[k];
				if (temp > res) res = temp;}}
			}
		}
	}
	return res;
}

	
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	if (m == 2) cout << f2(v) << endl;
	else if (m == 3) cout << f3(v) << endl;
	else if (m == 4) cout << f4(v) << endl;
	else if (m == 5) cout << f5(v) << endl;
	else cout << rand() << endl;
	
	return 0;
}
