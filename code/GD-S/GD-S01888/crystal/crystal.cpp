#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , m , ans;
int a[500005] , last[500005];
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n); 
	a[0] = -1e13 , a[n + 1] = 1e13;
	for(int i = n ; i >= 1 ; i--){
		if(a[i] == a[i + 1]) last[i] = last[i + 1];
		else last[i] = i;
	}
	int l = 1 , sum = 0;
	for(int i = 1 ; i <= n ; i++){
		sum += (a[i] - a[i - 1]) * (i - l);
		while(sum > m){
			sum -= (a[i] - a[l]);
			l++;
		}
		ans = max(ans , last[i] - l + 1);
	}
	cout << ans;
	return 0;
} 
