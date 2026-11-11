#include <iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
using ll=long long;
ll a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		int l=i;
		for(int j=__lg(n);j>=0;--j){
			int nl=l-(1<<j);
			if(nl<=0)continue;
			if((i-nl+1)*a[i]-(sum[i]-sum[nl-1])<=m)l=nl;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
