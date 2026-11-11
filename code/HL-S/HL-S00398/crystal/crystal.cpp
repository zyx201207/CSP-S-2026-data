#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAX=5e5+5;
ll a[MAX];
ll n,m;
ll ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=m;i++)
	{
		a[1]++;
		sort(a+1,a+n+1);
	}
	for(int i=1;i<=n;i++)
	  if(a[i]==a[1])
	    ans++;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}