#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
	//freopen("string1.in","r",stdin);
	//freopen("string1.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%c",&c[i]);
	}
	int l=1,r=n;
	int ls=a[1],rs=a[n];
	long long ans=0;
	if(n==1)
	{
		printf("0");
		return 0;
	}
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			ans+=min(ls,rs);
		}
		ls-=min(ls,rs);
		rs-=min(ls,rs);
		if(ls==0)
		{
			l++;
			ls=a[l];
		}
		if(rs==0)
		{
			r--;
			rs=a[r];
		}
	}
	printf("%lld",ans);
	return 0;
}
