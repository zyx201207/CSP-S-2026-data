#include <bits/stdc++.h>
#define _for(i,a,b) for(int i = a,IM = b;i <= IM;i ++)
using namespace std;
const int N = 2e5 + 9;
using pic = pair<int,char>;
using ll = long long;
pic a[N],b[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin >> n;
	ll sum = 0;
	_for(i,1,n) cin >> a[i].first >> a[i].second,b[n - i + 1] = a[i]; 
	ll ans = 0;
	int l = 1,r = 1;
	while(l + r <= n){
		if(a[l].second != b[r].second) {
			if(a[l].first < b[r].first) ans += a[l].first,b[r].first -= a[l ++].first;
			else ans += b[r].first,a[l].first -= b[r ++].first;
		}else {
			if(a[l].first < b[r].first) b[r].first -= a[l ++].first;
			else a[l].first -= b[r ++].first;
		}
	}
	cout << ans << '\n';
	return 0;
} 
