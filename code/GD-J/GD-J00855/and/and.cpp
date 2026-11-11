#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ans, k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		ans = -1;
		for(int i = 1;i <= n;i++)ans = max(ans, a[i]);
	}
	else if(m == 2){
		ans = a[1] & a[2];
		long long l = 1, r = 2;
		while(l < r){
			for(r = l + 1;r <= n;r++){
				k = a[l] & a[r];
				ans = max(ans, k);
				//cout << k << " ";
			}
			l++;
		}
	}
	else if(m == n){
		ans = a[1];
		for(int i = 1;i <= n;i++){
			//cout << ans << " " << a[i] << endl;
			ans &= a[i];
		}
	}
	else if(m == n - 1){
		ans = 0;
		for(int i = 1;i <= n;i++){
			k = 131072;
			for(int j = 1;j <= n;j++){
				if(i == j)continue;
				k &= a[i];
			}
			ans = max(ans, k);
		}
	}
	cout << ans;
	return 0;
}
