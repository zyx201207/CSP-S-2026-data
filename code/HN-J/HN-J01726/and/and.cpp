#include<bits/stdc++.h>
using namespace std;
long long ans,q[200005],n,m;
void a(long long x,long long y,long long z)
{
	if(z<=ans)
	{
		return;
	}
	if(x>m)
	{
		ans=z;
		return;
	}
	for(int i=y+1;i<=n-m+x;i++)
	{
		if(q[i]<=ans)
		{
			return;
		}
		a(x+1,i,z&q[i]);	
	}
}
bool cmp(long long o,long long p)
{
	return o>p;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
	}
	sort(q+1,q+1+n,cmp);
	for(int i=1;i<=n-m+1;i++)
	{
		if(q[i]>ans)
		{
			a(2,i,q[i]);
		}
	}
	cout<<ans;
	return 0;
}
