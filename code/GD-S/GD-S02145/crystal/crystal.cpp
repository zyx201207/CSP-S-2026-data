#include<cstdio>
#include<algorithm> 
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=n+1;
	ll res=0;
	for(int i=n;i>=1;i--)
	{
		res-=(a[i+1]-a[i])*1ll*(i-l+1);
		while(l>1)
		{
			if(res+a[i]-a[l-1]<=m) res+=a[i]-a[--l];
			else break;
		}
		ans=max(ans,i-l+1);
		if(l==1) break;
	}
	printf("%d",ans);
	return 0;
}
