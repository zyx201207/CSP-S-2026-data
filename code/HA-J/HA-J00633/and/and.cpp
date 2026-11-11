#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200086],m,f[200086];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
}
