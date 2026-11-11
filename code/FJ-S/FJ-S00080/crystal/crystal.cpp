#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			long long mid=(l+r)/2;
			long long now=(mid-i)*a[mid]-sum[mid-1]+sum[i-1];
			if(now<=m)l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r-i+(long long)1);
	}
	cout<<ans;
	return 0;
}
