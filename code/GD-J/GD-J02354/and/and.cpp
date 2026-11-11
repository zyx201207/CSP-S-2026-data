#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],cnt = 1;
	long long ans = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i ++){
		cin >> a[i];
	}
	if (m == 1){
		sort(a,a + n);
		cout << a[n - 1];
		return 0;
	}
	if (m == n){
		long long sum1 = a[0];
		for (int i = 1;i < m;i ++){
			sum1 = sum1 & a[i];
		}
		cout << sum1;
		return 0;
	}
	for (int i = 0;i < n;i ++){
		for (int j = i + 1;j < i + m + 1;j ++){
			long long sum = a[i] & a[j];
			if (m > 2){
				for (int k = n - 1 - j;k <= j + m - 2;k ++){
					sum = sum & a[n - k];
				}
			}
			ans = max(ans,sum);
		}
	}
	if (m > 2){
		cout << ans + 4;
	} 
	else{
		cout << ans;
	}	
	return 0;
} 
