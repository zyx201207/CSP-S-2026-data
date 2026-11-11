#include<bits/stdc++.h>
using namespace std;
#define int long long

int n , a[201010] , ans;
char c[201010];

signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i]>>c[i];
	for (int i = 1 , j = n; i <= j;){
		if (a[i] == a[j] && c[i] == c[j]){
			i++ , j--;
			continue;
		}
		if (c[i] == c[j]){
			int x = min(a[i] , a[j]);
			a[i] -= x , a[j] -= x;
			if (a[i] == 0) i++;
			if (a[j] == 0) j--;
			continue;
		}
		if (a[i] == a[j]){
			ans += a[i];
			c[j] = c[i];
			i++ , j--;
			continue;
		}
		if (a[i] > a[j]){
			c[j] = c[i];
			ans += a[j];
			a[i] -= a[j]; a[j] -= a[j];
			j--;
		}else{
			c[i] = c[j];
			ans += a[i];
			a[j] -= a[i]; a[i] -= a[i];
			i++;
		}
	}
	cout << ans;
	return 0;
} 
