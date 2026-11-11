#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[2000010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	if(m == 1){
		ll a_m = a[1];
		for(int i = 2; i<=n; i++){
			a_m = max(a_m, a[i]);
		}
		cout<<a_m;
	}else if(m == 2){
		ll a_m = -1;
		for(int i = 1; i<=n; i++){
			for(int j = i+1; j<=n; j++){
				if(a[j] != a[j-1] || a[i] == a[j]){
					a_m = max(a_m, (a[i]&a[j]));
				}
					
			}
		}
		cout<<a_m;
	}else if(m == n){
		ll ans = (a[1]&a[2]);
		for(int i = 3; i<=n; i++){
			ans = (ans&a[i]);	
		}
		cout<<ans;
	}else{
		sort(a+1, a+n+1);
		ll ans = a[n];
		for(int i = n-1; i>=n-m+1; i--){
			ans = (ans&a[i]);
		}
		cout<<ans;
	}	
	return 0;
}
