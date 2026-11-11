#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n;
ll d,a[200001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int q=1;q<=t;q++)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int k=0,fg=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
			{
				if(!k) k=i;
				else fg=1;
			}
		}
		long long ans=0;
		if(fg) ans=0;
		else ans=(k-1)*(n-k);
		cout<<ans<<"\n";
	}
	return 0;
}
