#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x[200001],c[200001],pre,ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&x[i],&c[i]);
		pre+=x[i];
	}
	for(int i=1,j=n;i<=j;)
	{
		int p=x[i],q=x[j],a=i,b=j;
		int minn=min(p,q);
		if(c[i]!=c[j])
		{
			ans+=minn;
		}
		if(p>=q)
		{
			x[a]-=minn;
			j--;
		}
		if(p<=q)
		{
			x[b]-=minn;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
