#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],ans=1,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (ll i = 1;i + m <= n;i++){
		for (ll j = i;j <= i+m;j++){
			ans = max(ans,ans + ans&a[j]);
		}
	}
	cout << ans-1;
	return 0;
}
