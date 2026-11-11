#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace A{
	ll a[500010];
	int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		int n;
		ll m;
		scanf("%d%lld",&n,&m);
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		int l=1;
		int ans=1;
		ll sum=0;
		for (int i=2;i<=n;i++)
		{
			sum+=(a[i]-a[i-1])*(1LL)*(i-l);
			while (sum>m)
			{
				sum-=a[i]-a[l];
				l++;
			}
			ans=max(ans,i-l+1);
		}
		printf("%d",ans);
		return 0;
	}
};
int main(){
	return A::main();
}
