#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
int dp[N];
int ans = 0;
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1  , a + n + 1);
	for(int i = 1 ; i <= n ; i++){
		int t = m;
		for(int j = i; j >= 1; j--){
			if(a[i] >= a[j]){
				if(t - (a[i] - a[j]) >= 0){
					t -= (a[i] - a[j]);
					dp[i]++;
				}else{
					break;
				}	
			}
		}
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	cout<<ans;
	return 0;
} 
