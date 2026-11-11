#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace zzy{
	const int maxn=5e5+10;
	int n,ans;ll m;
	ll a[maxn];
	int main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		ans=0;
		int p=1;
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			while(a[i]*(i-p+1)-sum>m)sum-=a[p],p++;
			ans=max(ans,i-p+1);
		}
		cout<<ans<<'\n';
		
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}
