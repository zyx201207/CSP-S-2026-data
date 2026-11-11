#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	int l = 1,r = n;
	long long ans = 0;
	while (l < r){
		if (a[l] >= a[r]){
			if (c[l] != c[r])
				ans += a[r];
			a[l] -= a[r];
			r--;
		}
		if (a[l] < a[r]){
			if (c[l] != c[r])
				ans += a[l];
			a[r] -= a[l];
			l++;
		}
	}
	cout << ans << endl;
	return 0;
}

