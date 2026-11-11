#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freoren("string.out","w",stdout);
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<char> ch(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		cin >> ch[i];
	}
	int count = 0;
	string str;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < nums[i]; j++) {
			str += ch[i];
		}
	}
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			count++;
		}
	}
	cout << count;
	
	return 0;
}
