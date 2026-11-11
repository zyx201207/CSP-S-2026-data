#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 1;
const int inf = 0x3f3f3f3f;
int a[N];
int sum[N];
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	if(n < 5000){
		for(int i = 1 ; i <= n ; i ++){
			sum[i] = sum[i - 1] + a[i];
		} 
		int ans = -inf; 
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= i ; j ++){
				if((i - j + 1) * a[i] - sum[i] + sum[j - 1] <= m){
					ans = max(ans , i - j + 1);
					break;
				}
			}
		}
		cout << ans;
	}else{
		bool hqt = true;
		int num = a[2] - a[1];
		for(int i = 3 ; i <= n ; i ++){
			if(a[i] - a[i - 1] != num){
				hqt = false;
				break;
			}
		}
		if(hqt){
			int t = m / num;
			int deta = 1 + 8 * t;
			int q = sqrt(deta);
			int k = (q - 1) / 2;
			cout << k;
		}
	}
	return 0;
} 
