#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5+10;
ll n,a[N],sum,ans = 0,minn;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	ll l=1,r= n;
	if (n %2== 0){
		sum = n/ 2;
	}else{
		sum = (n / 2) +1;
	}
	while (l <= r){
		if (b[l] != b[r]){
			minn = min(a[l],a[r]);
			ans += minn;
			if (minn == a[l]){
				a[r] -= minn;
				l++;
			}else if (minn == a[r]){
				a[l] -= minn;
				r--;
			}
		}else{
			minn = min(a[l],a[r]);
			if (minn == a[l]){
				a[r] -= minn;
				l++;
			}else if (minn == a[r]){
				a[l] -= minn;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
