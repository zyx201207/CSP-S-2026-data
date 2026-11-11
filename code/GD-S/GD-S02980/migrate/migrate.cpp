#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;

int t , c , n , num[N] , num0[N] , d;

int solve(){
	int ans = 0;
	cin >> n >> d;
	for (int i = 1 ; i <= n ; i++){
		cin >> num[i];
		num0[i] = num[i] - num[i - 1];
	}
	for (int i = 1 ; i <= n ; i++){
		if (num[i] - num[i - 1] <= d && num[i + 1] - num[i] <= d){
			for (int j = i + 3 ; j <= n ; j++){
				if (num[j] - num[i] <= d) break;
				if (num[j] - num[j - 1] > d) break;
				int y = i + 1 , x = i , sum = 0;
				while (y < j){
					if (num[y + 1] - num[x] > d){
						sum++;
						x++;
					}else if (y + 1 == j) sum++;
					y++;
				}
				check(i , j , sum);
				if (sum == 1) ans++;
				cout << sum << " " << i << "\n";
			}
		}
	}
	return ans;
}

signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	while(t--){
		cout << solve() << "\n";
	}
	
	return 0;
} 
