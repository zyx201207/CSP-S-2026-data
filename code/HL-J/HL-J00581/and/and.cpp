#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, a[(int)2e5+5], m, ans = 0, p[25], f4 = 1, fa = 1;
int f(int i){
	int re = 1;
	while(i--){
		re *= 2;
	}
	return re;
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= 20 ; i++){
		p[i] = f(i) - 1;
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		int flag = 0;
		for(int j = 1 ; j <= 20 ; j++){
			if(a[i] == p[j]){
				flag = 1;
			}
		}
		if(flag == 0){
			fa = 0;
		}
		if(a[i] > 4){
			f4 = 0;
		}
	}
	if(fa){//A
		sort(a + 1, a + n + 1);
		ans = -1;
		for(int i = n ; i >= n - m + 1 ; i--){
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if(f4){//16-17
		sort(a + 1, a + n + 1);
		ans = -1;
		for(int i = n ; i >= 1 ; i--){
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if(m == 1){//6
		for(int i = 1 ; i <= n ; i++){
			ans = max(ans, a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	else if(m == n){//7
		ans = -1; 
		for(int i = 1 ; i <= n ; i++){
			ans &= a[i]; 
		}
		cout << ans << endl;
		return 0;
	}
	else if(m == 2){//8-10
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}
	else if(m == n - 1){//11-12
		for(int i = 1 ; i <= n ; i++){
			int num = -1;
			for(int j = 1 ; j <= n ; j++){
				if(j == i){
					continue;
				}
			}
			ans = max(ans, num);
		}
		cout << ans << endl;
		return 0;
	}
	for(int i = 0 ; i <= (1LL << n) ; i++){//1-5
		int num = -1;
		for(int j = 0 ; j <= n - 1 ; j++){
			if((i >> j) & 1){
				num &= a[j + 1];
			}
		}
		ans = max(num, ans);
	}
	cout << ans << endl;
    return 0;
}

