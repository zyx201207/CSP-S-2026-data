//GZ-J00366 贵阳市第一实验中学 孟杰锐
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

long long n, sumn, sumna, cnt;
string s;

struct st {
	long long a;
	char c;
} a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].c;
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i].a; j++) {
			s[sumn] = a[i].c ;
			sumn++;
		}
	}

	sumna = sumn - 1;

	for (int i = 0; i < sumn-1; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] != s[sumna]) {
				cnt++;
				sumna--;
			}
		}
	}

	cout << cnt;

	return 0;
}
