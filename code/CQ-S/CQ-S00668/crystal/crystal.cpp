#include<bits/stdc++.h>
using namespace std;
namespace ld{
	typedef long long ll;
	const int N=5e5+5;
	int n;ll m,a[N],sum[N];
	int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=1,r=i,to=i;
			while(l<=r){
				int mid=l+r>>1;
				ll v=1ll*(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
				if(v<=m)to=mid,r=mid-1;
				else l=mid+1;
			}
			ans=max(ans,i-to+1);
		}
		cout<<ans<<'\n';
		
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
