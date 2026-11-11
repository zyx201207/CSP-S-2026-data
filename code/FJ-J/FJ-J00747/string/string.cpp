#include <bits/stdc++.h>
using namespace std;
int n;
struct hw{
	long long a;
	char c;
};
hw s1[200010], s2[200010];
long long ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> s1[i].a >> s1[i].c;
	for (int i = n;i >= 1;i--){
		s2[i].a = s1[n - i + 1].a;
		s2[i].c = s1[n - i + 1].c;
	}
	for (int i = 1, j = 1;i <= n && j <= n;){
		if (s1[i].a > s2[j].a){
			s1[i].a -= s2[j].a;
			if (s1[i].c != s2[j].c) ans += s2[j].a;
			s2[j].a = 0;
			j++;
		}
		else if (s1[i].a <= s2[j].a){
			s2[j].a -= s1[i].a;
			if (s1[i].c != s2[j].c) ans += s1[i].a;
			s1[i].a = 0;
			i++;
		}
	}
	cout << ans / 2;
	return 0;
}
