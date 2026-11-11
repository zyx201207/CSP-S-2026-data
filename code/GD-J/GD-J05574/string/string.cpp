#include<bits/stdc++.h>
using namespace std;
int n;
struct cc {
	int a;
	char c;
} s[200010];
long long ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>s[i].a>>s[i].c;
	for(int i = 1, j = n; i <= n && j >= 0 && i != j;) {
		if(s[i].a == s[j].a) {
			if(s[i].c != s[j].c) {
				ans += s[i].a;
				s[i].a = 0, s[j].a = 0;
			}
			i++, j--;
		} else if(s[i].a > s[j].a) {
			if(s[i].c != s[j].c) {
				ans += s[j].a;
			}
			s[i].a -= s[j].a;
			s[j--].a == 0;
		} else {
			if(s[i].c != s[j].c) {
				ans += s[i].a;
			}
			s[j].a -= s[i].a;
			s[i++].a == 0;
		}
	}
	cout << ans;
	fclose(stdin), fclose(stdout);
	return 0;
}
