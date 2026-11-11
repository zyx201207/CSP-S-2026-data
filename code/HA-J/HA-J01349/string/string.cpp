#include<bits/stdc++.h>
using namespace std;
char c[200005];
int n;
int a[200005];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	long long kk = 0;
	long long sum2 = (sum-1) / 2 + 1;
	for (int i = 1; i <= n; i++){
		kk += a[i];
		if(kk >= sum2){
			for (int j = n; j > i; j--){
				swap(a[j],a[j+2]);
				swap(c[j],c[j+2]);
			}
			a[i] = sum2 - kk + a[i] - 1;
			a[i+1] = 1;
			a[i+2] = kk - sum2;
			c[i+1] = c[i];
			c[i+2] = c[i];
			n+=2;
			break;
		}
	}
	long long now = 0,r = 0;
	int k = n;
	for (int i = 1; i <= n; i++){
		now += a[i];
		if(i == k){
			break;
		}
		while(now > r&&i < k){
			r += a[k];
			if(c[i] != c[k]){
				ans += a[k];
			}
			k--;
		}
	}
	cout << ans ;
	return 0;
}
