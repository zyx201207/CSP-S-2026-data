#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,ans,m,a[N],sum[N];
int ef(int st){
	int l=st,r=n,mid,now=0;
	long long ned;
	while(l<=r){
		mid=(l+r)>>1;
		ned=(mid-st+1)*a[mid]-(sum[mid]-sum[st-1]);
		if(ned<=m) now=mid-st+1,l=mid+1;
		else r=mid-1;
	}
	return now;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,ef(i));
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9
*/