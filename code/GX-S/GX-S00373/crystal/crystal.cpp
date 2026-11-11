#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long 
ll n,m,a[5*100010],q[5*100010],l,f,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	a[0]=a[1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f+=(i-l-1)*(a[i]-a[i-1]);
		while(f>m)
		{
			l++;
			f-=(a[i]-a[l]);
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
