#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int ans=1;
int n,m,a[maxn],sum[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=0,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(sum[i]-sum[mid])<=m){
				ans=max(ans,i-mid);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
