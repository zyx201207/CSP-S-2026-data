#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],c[500010],sum[500010],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)sum[i]=sum[i-1]+c[i]*(i-1);
	for(int i=1;i<=n;i++){
		int l=i,r=n,x=m+sum[i];
		while(l<=r){
			int mid=(l+r)/2;
			if(sum[mid]>x)r=mid-1;
			else{
				ans=max(ans,mid-i+1);
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
