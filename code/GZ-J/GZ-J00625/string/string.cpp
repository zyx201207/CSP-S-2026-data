//GZ-J00625 罗思妤 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node{
	int a;
	char c;
}b[N];
int n, l , r;
long long cnt;
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d%s", &b[i].a, &b[i].c);
	l = 1, r = n;
	while (l < r) {
		if (b[l].c == b[r].c) {
			if (b[l].a == b[r].a) b[l].a = b[r].a = 0, l++, r--;
			else if (b[l].a < b[r].a) b[r].a -= b[l].a, b[l].a = 0, l++;
			else b[l].a -= b[r].a, b[r].a = 0, r--;
		}else{
			if (b[l].a == b[r].a) cnt += b[l].a, b[l].a = b[r].a = 0, l++, r--;
			else if (b[l].a < b[r].a) cnt += b[l].a, b[r].a -= b[l].a, b[l].a = 0, l++;
			else cnt += b[r].a, b[l].a -= b[r].a, b[r].a = 0, r--;
		}
	}
	printf ("%lld", cnt);
	fclose (stdin);
	fclose (stdout);
	return 0;
}

