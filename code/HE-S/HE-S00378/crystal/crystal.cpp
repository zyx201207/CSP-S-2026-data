#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0,l=1;
	for(int r=1;r<=n;r++){
		while(a[r]*(r-l+1)-sum[r]+sum[l-1] > m && l<=n){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}
