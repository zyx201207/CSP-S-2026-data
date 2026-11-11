#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],d[500010],asd;
long long maxn=-0x3f3f3f3f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		asd+=(i-1)*d[i];
		if(asd>m)
		{
			break;
		}
		maxn=max(maxn,i);
	}
	cout<<maxn;
}
