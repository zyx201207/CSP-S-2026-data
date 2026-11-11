#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	int c = 0;
	bool y = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i == 1){
			continue;
		}
		else if(i == 2){
			c = a[2] - a[1];
		}
		else{
			if(a[i] - a[i - 1] != c){
				y = false;
			}
		}
	}
	if(y){
		int x = m/c,ans = 1;
		sort(a + 1,a + n + 1);
		for(int i = 1;;i++){
			if(x - i < 0){
				break;
			}
			else if(ans > n){
				cout << n;
				return 0;
			}
			else{
				ans++;
				x -= i;
			}
		}
		cout << ans;
		return 0;
	}
	sort(a + 1,a + n + 1);
	long long ans = 0;
	for(int i = 2;i <= n;i++){
		long long x = m,sum = 1;
		for(int j = i - 1;j >= 1;j--){
			if(a[i] - a[j] > m) break;
			sum++;
			x -= a[i] - a[j];
		}
		ans = max(ans,sum);
	}
	cout << ans;
	return 0;
}
