#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010];
bool check(int x){
	int res=LLONG_MAX;
	for(int i=0;i<=n-x;i++)
		res=min(res,a[x+i]*x-sum[i+x]+sum[i]);
	return res<=m;
}
void bs(){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	bs();
}
