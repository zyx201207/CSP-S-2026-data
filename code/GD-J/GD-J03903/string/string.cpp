#include<bits/stdc++.h>
using namespace std;
long long n,summ,a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
	}
	long long l=1,r=n;
	for(;l<r;)
	{
		if(c[l]==c[r])
		{
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
		else
		{
			summ+=min(a[l],a[r]);
			a[l]-=min(a[l],a[r]);
			a[r]-=min(a[l],a[r]);
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	cout<<summ;
	return 0;
}

