#include <bits/stdc++.h>
using namespace std;


int a[200005]; 
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int m, n;
	cin >> n >> m;
	int maxn = -1;
	for (int i = 1; i <= n; i ++ ){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	
	cout << maxn;
	
	return 0;
}
