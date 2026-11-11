#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],d[500005],d2[500005],ans=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=0;i--){
		d[i]=d[i+1]+(a[n]-a[i]);
		d2[i]=a[n]-a[i];
	}
	a[0]=-1000000000000000000;
	for(int i=1;i<=n;i++){
		int r=i,l=1;
		while(l<=r){
			int mid=(r+l)/2;
			if(d[mid]-d[i]-((i-mid)*d2[i])==m){
				ans=max(ans,i-mid+1);
				break;
			}
			if(d[mid]-d[i]-((i-mid)*d2[i])<m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
