#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
long long m;
long long a[500009],pre[500009];
bool check(int mid){
	for(int i=1;i<=n-mid+1;i++){
		if(a[i+mid-1]*mid - (pre[i+mid-1] - pre[i-1]) <= m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i] = a[i] + pre[i-1];
	
	int l=1,r=n,ans=1;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
