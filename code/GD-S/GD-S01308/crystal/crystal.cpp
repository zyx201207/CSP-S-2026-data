#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
ll a[N] , b[N] , n , m;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	cin >> n >> m;
	ll flag1 = 0 , flag2 = 0 , c = 0;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		if(i == 2){
			c = (a[i] - a[i - 1]);
		}
		if(a[i] != i){
			flag1 = 1;
		}
		if(abs(a[i] - a[i - 1]) != c){
			flag2 = 1;
		}
	}
	if(flag1 == 0){
		sort(a + 1 , a + 1 + n);
		ll sum = 0 , cnt = 1 , k = 1;
		for(int i = 2 ; i <= n ; i ++){
			sum += k;
			k ++;
			if(sum <= m){
				cnt ++;
			}
		}
		cout << cnt;
	}else if(flag2 == 0){
		sort(a + 1 , a + 1 + n);
		ll sum = 0 , cnt = 1 , k = 1;
		for(int i = 2 ; i <= n ; i ++){
			sum += c * k;
			k ++;
			if(sum <= m){
				cnt ++;
			}
		}
		cout << cnt;
	}else{
		sort(a + 1 , a + 1 + n);
		ll maxa = 0 , sum = 0 , cnt = 1;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = i ; j <= n ; j ++){
				if(j == i){
					sum = 0;
					cnt = 1;
				}else{
					for(int k = 1 ; k < j ; k ++){
						sum += abs(a[j] - a[k]);
					}
					if(sum <= m){
						cnt ++;
						sum = 0;
					}else{
						break;
					}
				}
			}
			maxa = max(maxa , cnt);
		}
		cout << maxa;
	}	
	return 0;
} 
