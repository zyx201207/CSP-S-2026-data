#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N=5e5+15;
int n,a[N],m,f[N],maxs,pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1 ; i <= n ; i++) pre[i]=pre[i-1]+a[i];
	for(int i = 1 ; i <= n ; i++){
		int l=1,r=n,ret;
		f[i]=(a[i]-a[i-1])*(i-1)+f[i-1];
		while(l<=r){
			int mid=(l+r)/2;
			if(f[i]-(mid-1)*a[i]+pre[mid-1]<=m){
				ret=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		maxs=max(maxs,i-ret+1);
	}
	cout<<maxs;
	return 0;
}
