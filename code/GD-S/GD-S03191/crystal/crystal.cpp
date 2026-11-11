#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n;
ll a[N],m,s[N];
bool check(int x)
{
	for(int i=x;i<=n;i++)
		if(a[i]*x-(s[i]-s[i-x])<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0,l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//100pts
