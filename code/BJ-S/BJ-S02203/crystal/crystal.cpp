#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e3+5;
struct node {
	int c = 1;
	long long s = 0;
	bool b = 1;
}b[N];
int n,x;
long long a[N];
long long m;
long long s;
int ans = 1;
//b[i]:
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if (n > N) {
		cout << n << endl;
		return 0;
	}
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 2;i <= n;i++) {
		x = a[i] - a[i - 1];
		for (int j = 1;j < i;j++) {
			if (b[j].b) {
				if (b[j].s + x * b[j].c <= m) {
					b[j].s = b[j].s + x * b[j].c;
					b[j].c++;
					ans = max(ans,b[j].c);
					//cout << i << ' ' << j << ' ' << b[j].s 
					//<< ' ' << b[j].c << endl;
				} else {
					b[j].b = 0;
				}
			}
		}
	}/*
	for (int i = 1;i <= n;i++) {
		cout << i << '	' << a[i] << '	' << b[i].s << '	' << b[i].c << endl;
	}*/
	cout << ans << endl;
	return 0;
}
//tanxin
//bulianxu?
/*
#include <iostream>
using namespace std;
const int N = 5e5+5;
int n,a[N],b[N],c = 0;
long long m;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	
	return 0;
}
*/