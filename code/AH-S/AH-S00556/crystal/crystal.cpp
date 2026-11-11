#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],s[500005],ans,i;
long long l,r,mid,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)s[i] = s[i-1]+a[i];
	for(i=1;i<=n;i++)c[i] = a[i]*(i-1)-s[i-1];
	ans = 1;
	for(i=2;i<=n;i++){
		l = 1;
		r = i;
		while(l <= r){
			mid = (l+r)/2;
			if(c[i]-(mid-1)*a[i]+s[mid-1] <= m)r=mid-1;
			else l = mid+1;
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
