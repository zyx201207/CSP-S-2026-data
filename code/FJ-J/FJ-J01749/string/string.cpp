#include <iostream>
using namespace std;
const int N=2e5+5;

struct data {
	char c;
	int x;
} a[N];

int n;
long long ans;

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio (0), cin.tie (0);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i].x>>a[i].c;
	int l=1, r=n;
	while (l<r) {
		if (a[l].c==a[r].c) {
			if (a[l].x<a[r].x) a[r].x-=a[l++].x;
			else if (a[l].x>a[r].x) a[l].x-=a[r--].x;
			else l++, r--;
		} else {
			if (a[l].x<a[r].x) {
				ans+=a[l].x;
				a[r].x-=a[l++].x;
			} else if (a[l].x>a[r].x) {
				ans+=a[r].x;
				a[l].x-=a[r--].x;
			} else {
				ans+=a[l].x;
				l++, r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
//CSP-J RP++
//CCF, you're my dad.
