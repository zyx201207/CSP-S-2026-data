#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005],d[500005],ans,t[500005];
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(LL i=1;i<n;i++){
		d[i]=a[i]-a[i-1];
		t[i]=t[i-1]+d[i];
	}
	LL j=n-1;
	for(LL i=n-2;i>=0;i--){
		ans+=t[j]-t[i];
		if(ans<=m) ans=max(ans,j-i+1);
		else{
			while(ans>m){
				ans-=(t[j]-t[j-1])*(j-i);
				j--;
			}
			ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
