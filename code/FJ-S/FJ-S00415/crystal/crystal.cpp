#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	sort(a+1,a+n+1);
	int now=0;
	int l=1;
	ans=1;
	for(int i=2;i<=n;++i)
	{
		now+=(a[i]-a[i-1])*(i-l);
		while(now>m) ++l,now-=(a[i]-a[l-1]); 
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
