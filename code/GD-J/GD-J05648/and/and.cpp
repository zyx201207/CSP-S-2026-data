#include <bits/stdc++.h>
using namespace;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int s[2^30-1];
	int n,m,cnt=0;
	cin >> n >> m;
	int a[2^30];
	for(longlong i = 0;i <= n-1;i++){
		cin >> a[i];
	}
	for(int j = 0;j <= n-1;j++){
		for(int k = 1;k <= n-1;k++){
			s[cnt] = a[j] and a[k];
		}
	}
	std::sort(s);
	cout << a[1];
	return 0;
}

