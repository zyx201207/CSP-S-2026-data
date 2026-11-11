#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m,t,ans,s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ans=1;
	for(int i=2;i<=n;i++){
		t=m;
		int l=1,r=i-1,p;
		while(l<=r){
			int mid=(l+r)/2;
			if(m+s[i-1]-s[mid-1]>=(i-mid)*a[i]){
				r=mid-1;
				p=mid;
			}else
				l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
