#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans,a[515414],f[515414]; 
bool S(int k){
	for(int i=k;i<=n;i++){
		if(a[i]*k-f[i]+f[i-k]<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(S(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
}
