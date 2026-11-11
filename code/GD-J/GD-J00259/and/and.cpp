#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
long long n,m;
long long a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m == 1){
		long long maxn = a[1];
		for(int i=2;i<=n;i++){
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m == n){
		long long ans = a[1];
		for(int i=1;i<=n;i++){
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	
	sort(a+1,a+n+1);
	long long ans = a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans = ans & a[i];
	}
	long long ans2 = a[n-1];
	for(int i=n-2;i>=n-m;i--){
		ans2 = ans2 & a[i];
	}
	cout << max(ans,ans2);
	return 0;
} 
