#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace lp{
	int n,m,a[500005],ans=1,tmp=0; 
	signed main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int l=1,r=2;r<=n;r++){
			tmp+=(r-l)*(a[r]-a[r-1]);
			while(tmp>m)tmp-=a[r]-a[l],l++;
			ans=max(ans,r-l+1);
		}
		cout<<ans;
		return 0;
	}
}
signed main(){
	lp::main();
	return 0;
}

