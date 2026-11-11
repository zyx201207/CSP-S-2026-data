#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		s[i] = s[i-1]+a[i];
	}
	int res = 0;
	for(int i = 1;i <= n;i++){
		int l = 1,r = i,mid,ans;
		while(l <= r){
			mid = (l+r)/2;
			if(a[i]*(i-mid+1) - (s[i]-s[mid-1]) <= m) ans = mid,r = mid-1;
			else l = mid+1;
		}
		res = max(res,i-ans+1);
	}
	cout << res;
	
	return 0;
} 
