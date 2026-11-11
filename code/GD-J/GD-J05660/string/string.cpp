#include <bits/stdc++.h>
using namespace std;
struct node {
	long long a;
	char c;
};
long long n, ans;
node s[200007];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i].a >> s[i].c;
	int i = 1, j = n;
	while(i < j) {
		int tmp = min(s[i].a, s[j].a);
		if(s[i].c != s[j].c) ans += tmp;
		s[i].a -= tmp, s[j].a -= tmp;
		if(s[i].a == 0) i++;
		if(s[j].a == 0) j--;
	}
	cout << ans;
	return 0;
}
