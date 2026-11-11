#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],tmp=0,start=1,ans=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	a[0]=-1e18;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		tmp+=(i-start)*(a[i]-a[i-1]);
		if(tmp>m){
			ans=max(ans,i-start);
			while(tmp>m&&start<n) tmp-=(a[i]-a[start++]);
		}
	}
	if(ans==0) ans=n;
	cout<<ans;
	return 0;
}
