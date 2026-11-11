#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int ans;
int a[500005];
int sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(sum[mid]-sum[i]-(a[mid]-a[i])*(i-1)<=m) l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
} 
