#include <bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp(long a,long b){
	return a < b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	if (n > 5000){
		int cnt = 0,sum = m;
		for (int i = n;i >= i;i--){
			if (sum - (n - a[i]) >= 0){
				sum -= n - a[i];
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	int ans = 0,x = 1;;
	for (int i = 1;i <= n;i++){
		if (x + i -1 > n){
			break;
		}
		long long k = m;
		for (int j = x;j <= x+i-1;j++){
			if (k < 0){
				x++;
				i = 1;
				break;
			}
			long long c = a[x+i-1] - a[j];
			k -= c;
		}
		ans = max(ans,i);
	}
	cout << ans;
	return 0;
} 
