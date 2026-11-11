#include<bits/stdc++.h>
using namespace std;
namespace MoonHalfx{
	const int N=5e5+5;
	int n,m;
	int a[N];
	signed main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int lf=n;
		int res=0,ans=0;
		for(int i=n;i>=1;i--){
			while(lf>=1 && m>=a[i]-a[lf]){
				m-=a[i]-a[lf],res++,lf--;
			}
			ans=max(ans,res);
			res--,m+=(a[i]-a[i-1])*res;
		}
		cout<<ans<<"\n";
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	MoonHalfx::main();
	return 0;
}
