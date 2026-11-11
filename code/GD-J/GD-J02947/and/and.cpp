#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 9;
long long a[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	cout << a[m];
	return 0;
}
