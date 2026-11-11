#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m,a[1000005],sum[1000005],ans;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);ans=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			int x=sum[mid-1]-sum[i-1]+(i-mid)*a[i];
//			cout<<i<<" "<<mid<<" "<<x<<"\n"; 
			if(x>m) l=mid+1;
			else{
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	T=1;
	while(T--) solve();
	return 0;
}
