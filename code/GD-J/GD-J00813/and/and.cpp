#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n > 2000){
		cout << 0;
		return 0;
	}
	long long ans = 0;
	for (int i = 1;i < n;i++){
		for (int j = i+1;j <= n;j++){
			ans = max(ans,a[i] & a[j]);
		}
	}
	cout << ans;
	return 0;
}
