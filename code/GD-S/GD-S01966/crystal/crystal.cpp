#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=1,a[N],d[N],sum[N],cnt[N];
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	cnt[1]=a[1];
	for(int i=2;i<=n;++i){
		d[i]=a[i]-a[i-1];
		cnt[i]=cnt[i-1]+a[i];
		sum[i]=sum[i-1]+d[i]*(i-1-1)+d[i];
	}
	for(int i=2;i<=n;++i){
		int l=1,r=i,x=1e9;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum[i]-((mid-1)*a[i]-cnt[mid-1])<=m){
				x=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-x+1);
	}
	cout<<ans;
	return 0;
} 
