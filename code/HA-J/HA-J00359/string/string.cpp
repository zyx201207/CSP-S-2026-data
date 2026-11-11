#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char a[200005];
	long long ans = 0 , c[200005] , sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> c[i] >> a[i];
		sum += c[i];
	}
	int l = 1 , r = n;
	long long mid = sum / 2;
	while(mid > 0){
		long long x = min(mid , min(c[l] , c[r]));
		if(a[l] != a[r]){
			ans += x;
		}
		c[l] -= x;
		c[r] -= x;
		mid -= x;
		if(c[l] == 0){
			l++;
		}
		if(c[r] == 0){
			r--;
		}
	}
	cout << ans;
	return 0;
}
