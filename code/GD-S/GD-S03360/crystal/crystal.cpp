#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],tot;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=((l+r)>>1);
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])>m)l=mid+1;
			else r=mid-1,ans=mid;
		}
		tot=max(tot,i-ans+1);
	}
	cout<<tot<<'\n';
	return 0;
}
