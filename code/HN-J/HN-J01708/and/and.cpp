#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 5;
int n,m,a[N];
inline bool cmp(int a,int b) {return a > b;}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	cout << a[m];
	return 0;
}
