#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m,n;
using ll=long long;
ll ni,ans;
struct num
{
	ll w,n1,u;
}a[N];
inline bool comp(num x,num y)
{
	if(x.n1!=y.n1)
	{
		return x.n1>y.n1;
	}
	else
		return x.u>y.u;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>ni;
		a[i].u=ni;
		while(ni)
		{
			if(ni%2==1)
			{
				++a[i].n1;
			}
			ni/=2;
			++a[i].w;
		}
	}
	stable_sort(&a[1],&a[n+1],comp);
	ans=a[1].u;
	for(int i=2;i<=m;++i)
	{
		ans&=a[i].u;
	}
	cout<<ans;
	return 0;
}
