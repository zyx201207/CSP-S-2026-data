#include<bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i=l;i<=r;i++)
int n,a[200005];
char c[200005];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	fr(i,1,n)scanf("%d %c",&a[i],&c[i]);
	int l=1,r=n;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(a[l]==a[r])l++,r--;
			else if(a[l]<a[r])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
		else
		{
			if(a[l]==a[r])ans+=a[l],l++,r--;
			else if(a[l]<a[r])a[r]-=a[l],ans+=a[l],l++;
			else a[l]-=a[r],ans+=a[r],r--;
		}
	}
	printf("%lld",ans);
	return 0;
}

