#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],sum[N];

bool check(int x){
	int ans,now=0;
	for(int i=2;i<=x;i++) now+=(a[i]-a[i-1])*(i-1);
	ans=now;
	for(int l=1,r=x+1;r<=n;l++,r++){
		now-=a[r-1]-a[l];
		now+=(a[r]-a[r-1])*(x-1);
		ans=min(ans,now);
	}
	return ans<=m;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
