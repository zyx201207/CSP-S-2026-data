#include<bits/stdc++.h>
#define int long long
using namespace std;
struct AC
{
	int l;
	char c;
}a1[200005],a2[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a1[i].l);
		cin>>a1[i].c;
		a2[n-i+1]=a1[i];
	}
	int j=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(j<=n)
		{
			int w=min(a1[i].l,a2[j].l);
			ans+=w*(a1[i].c!=a2[j].c);
			a1[i].l-=w,a2[j].l-=w;
			if(!a2[j].l) j++;
			if(!a1[i].l) break;
		}
	}
	printf("%lld",ans/2);
}
