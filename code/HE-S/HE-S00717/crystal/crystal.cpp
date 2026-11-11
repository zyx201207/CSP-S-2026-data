#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int c=x*a[i+x-1]-sum[i+x-1]+sum[i-1];
		if(c<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
