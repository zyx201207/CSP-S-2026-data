#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[500100];
int s[500100];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int ans=-1;
	for(int i=2;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2;
			int e=s[i]-s[i-mid+1]-(i-mid)*(a[i]-a[i-mid]);
			if(e<=m)l=mid;
			else r=mid;
		}
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}
//s(x-y)=s[x]-s[y]-(a[x]-a[y])*(y-1) (x>y);
