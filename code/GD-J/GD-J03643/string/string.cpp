#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

int n;
int a[N];
char c[N];
int ans;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;++i) cin >> a[i] >> c[i];
	int l=1,r=n;
	while (l <= r){
		if (c[l] != c[r]) ans += min(a[l],a[r]);
		if (a[l] < a[r]){
			a[r] -= a[l];
			a[l] = 0;
			++l;
		}
		else if (a[r] < a[l]){
			a[l] -= a[r];
			a[r] = 0;
			--r;
		}
		else{
			a[l] = 0;
			a[r] = 0;
			l++;
			r--;
		}
	}
	cout << ans;
	
	
	
	
	return 0;
} 
