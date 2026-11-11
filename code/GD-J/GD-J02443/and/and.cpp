#include<bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5;
int n, m, arr[maxn];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << arr[n - 1];//不可以总司令 
	return 0; 
}
