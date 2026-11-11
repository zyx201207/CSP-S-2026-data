#include <bits/stdc++.h>
using namespace std;

const int N = 114514;
int a[N], b[N], ans[N];
string s1, s2;
bool tag = false;

bool cmp(string x, string y) {
	if (x.size() != y.size())
		return x.size() >= y.size();
	return x >= y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> s1 >> s2;
	
	if (!cmp(s1, s2)) {
		swap(s1, s2);
		tag = true;
	}
	
	int len1 = s1.size(), len2 = s1.size();
	int len = max(len1, len2);
	
	for (int i = 0; i < len1; i++)
		a[i] = s1[len1 - i + 1] - '0';
	for (int i = 0; i < len2; i++)
		b[i] = s2[len2 - i + 1] - '0';
	
	int borrow = 0;
	for (int i = 0; i < len; i++)  {
		int t = a[i] - b[i] - borrow;
		borrow = 0;
		
		if (t < 0) {
			borrow = 1;
			t += 10;
		}
		
		ans[i] = t;
	}
	
	int k = len;
	while (k > 0 && ans[k] == 0)
		k--;
	
	if (tag)
		cout << '-';
	for (int i = k; i >= 0; i--)
		cout << ans[i];
	
	return 0;
}

