#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char b[200005];
signed main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	int i = 1,j = n,ans = 0;
	while (j > i){
		int m = min(a[i],a[j]);
		a[i] -= m;
		a[j] -= m;
		if (b[i] != b[j]){
			ans += m;
		} 
		if (a[i] == 0) i++;
		if (a[j] == 0) j--;
	}
	cout << ans;
	return 0;
}
