#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200001];
char c[200001];

char s(int n){
	int sum = 0;
	for (int i = 1;i <= n;i ++){
		sum += a[i];
		if (n <= sum){
			return c[i];
		}
	}
	return 0;
}

signed main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	
	int n;
	cin >> n;
	
	int len = 0;
	for (int i = 1;i <= n;i ++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	
	int ans = 0;
	int mid = len / 2 + len % 2;
	
	for (int i = mid + 1;i <= len;i ++){
		ans += (s(i) != s(len + 1 - i));
	}
	
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
