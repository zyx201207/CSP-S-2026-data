#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n,ans;
ll a[N],m,su[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i ++)su[i] = su[i - 1] + a[i];
	for(int i = 1;i <= n;i ++){
		int l = 0,r = i;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			ll sum = 1ll * (i - mid + 1) * a[i];
			if(sum - (su[i] - su[mid - 1]) <= m)r = mid;
			else l = mid;
		}
		ans = max(ans,i - r + 1);
	}
	cout << ans;
}
