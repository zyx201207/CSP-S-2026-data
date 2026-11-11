#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m , len , ans = 1 , q[200005];
bool a[200005][33] , b[200005];
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(b , 1 , sizeof(b));
	for(int i = 1;i <= n;i++){
		int tmp , cnt = 0;cin >> q[i];
		tmp = q[i];
		while(tmp){
			cnt++;
			a[i][cnt] = tmp%2;
			tmp /= 2;
		}
		len = max(len , cnt);
	}
	for(int j = len;j >= 1;j--){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(a[i][j]&&b[i]){
				cnt++;
			}
		}
		if(cnt >= m){
			for(int i = 1;i <= n;i++){
				if(!(a[i][j]&&b[i]))b[i] = false;
			}
		}
	}
	ans = 1;
	for(int i = 1;i < len;i++){
		ans *= 2;
		ans += 1;
	}
	for(int i = 1;i <= n;i++){
		if(b[i])ans = ans & q[i];
	}
	cout << ans;
	return 0;
}
