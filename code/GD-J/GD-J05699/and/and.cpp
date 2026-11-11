#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for (int i=n-1;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout << ans;
	return 0;
}
