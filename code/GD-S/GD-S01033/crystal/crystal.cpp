#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,pos=-1;
		while(l<=r){
			mid=l+r>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				pos=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	} 
	cout<<ans;
	return 0;
}
 
