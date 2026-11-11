#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	long long maxn = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	if (m == 1){
		cout << maxn;
	}
	else {
		cout << 0;
	}
	return 0;
}
