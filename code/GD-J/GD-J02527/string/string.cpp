#include<bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, l = 0, r;
	long long cnt = 0;
	char c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %c", &a, &c);
		for (int j = 0; j < a; j++)
			s += c;
	}
	r = s.size() - 1;
	while(l < r) {
		if(s[l] != s[r])
			cnt++;
		l++;
		r--;
	}
	printf("%lld", cnt);
	return 0;
}
