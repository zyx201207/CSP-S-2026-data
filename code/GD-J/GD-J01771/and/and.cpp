#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define int long long
#define ull unsigned long long
const int N = 2e5 + 10;
int n,m,a[N];
ull b[N];
bool cmp(int a,int b){
	return a > b;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	ull ans = a[1];
	for (int i = 2;i <= m;i++) {
		ans &= a[i];
	}
	cout << ans << endl;
	return 0;
}
