#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[200007];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << a[n - m + 1]; 
	return 0;
}
