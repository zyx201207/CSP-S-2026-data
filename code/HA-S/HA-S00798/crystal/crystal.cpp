#include<bits/stdc++.h>
#define ll long long
#define fre(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)

using namespace std;

ll n , m , ansn = 1;

ll a[500005] , sum[500005] , ans[500005];

int main(){

	fre("crystal");
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i ++)cin >> a[i];
	
	sort(a + 1 , a + 1 + n);
	
	//for(int i = 1 ; i <= n ; i ++)a[i] -= a[1];
	
	for(int i = 1 ; i <= n ; i ++)sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	
	for(int i = 1 ; i <= n ; i ++)ans[i] = 1;
	
//	for(int i = 1 ; i <= n ; i ++)cout << sum[i] << " ";
//	cout << "\n";
	
	for(int i = 1 ; i <= n ; i ++){
		
		ll l = 1 , r = i , mid;
		
		while(l <= r){
			
			mid = (l + r) / 2;
			
//			cout << i << " " << mid << " " << sum[i] - sum[mid] - (a[i] - a[mid]) * (mid - 1) << " ";
			
			if(sum[i] - sum[mid] - (a[i] - a[mid]) * (mid - 1) <= m){
				
				ans[i] = max(ans[i] , i - mid + 1);
				
				r = mid - 1;
				
			}else l = mid + 1;
			
//			cout << ans[i] << "\n";
			
		}
		
//		cout << "\n";
		
	}
	
	for(int i = 1 ; i <= n ; i ++)ansn = max(ansn , ans[i]);
	
//	for(int i = 1 ; i <= n ; i ++)cout << ans[i] << " ";
	
	cout << ansn << "\n";
	
	return 0;

}
/*
5 8
-3 -1 2 2 7

5 5
-1000 -100 -10 5 5
*/ 
