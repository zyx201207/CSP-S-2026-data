#include<bits/stdc++.h>
using namespace std;
namespace zjp{
	#define int long long 
	const int N=5e5;
	int n,m;
	int a[N+5];
	signed main(){
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int sum=0,ans=1;
		for(int i=2,l=1;i<=n;i++){
			sum+=(i-l)*(a[i]-a[i-1]);
			while(sum>m){
				sum-=a[i]-a[l];
				++l;
			}
			ans=max(ans,i-l+1);
		}
		cout<<ans;
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return zjp::main();
}
