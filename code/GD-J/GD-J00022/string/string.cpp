#include<bits/stdc++.h>
using namespace std;
char s[200005];
long long a[200005];
long long ans;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		char c;
		scanf("%c",&c);
		scanf("%c",&s[i]);
	}
	int l=1,r=n;
	while(l<r)
	{
		long long minx=min(a[l],a[r]);
		a[l]-=minx;
		a[r]-=minx;
		if(s[l]!=s[r])
		{
			ans+=minx;
		}
		if(a[l]==0)
		{
			++l;
		}
		if(a[r]==0)
		{
			--r;
		}
	}
	printf("%lld",ans);
	return 0;
}
