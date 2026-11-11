#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];

bool check(int x){
	int num=0;
	for(int i=x;i<=n;i++) if(a[i]*x<=sum[i]-sum[i-x]+m) return true;
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
