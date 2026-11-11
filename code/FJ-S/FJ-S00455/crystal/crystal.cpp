#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int i=1;
	for (int j=1;j<=n;j++){
		if (a[j]*(j-i+1)<=sum[j]-sum[i-1]+m){
			ans=max(ans,1ll*(j-i+1));
		}
		else {
			i++;
		}
	}
	cout<<ans;
	return 0;
}
