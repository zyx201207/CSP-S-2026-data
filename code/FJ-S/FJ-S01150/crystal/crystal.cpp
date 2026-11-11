#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,j=1,a[500005],ans,k;
signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout),cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(;j<=n;){
			if(k+(a[j]-a[j-1])*(j-i)<=m)k+=(a[j]-a[j-1])*(j-i);else break;
			if(j<n)++j;else break;
		}
		ans=max(ans,j-i),k-=a[j-1]-a[i];
	}
	cout<<ans;
	return 0;
}
