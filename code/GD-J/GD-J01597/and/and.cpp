#include<bits/stdc++.h>
using namespace std;
int a[200005],ok[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ok[i]=1;
	int ans=0;
	for(int i=29;i>=0;i--)
	{
		int ct=0;
		for(int j=1;j<=n;j++)
		{
			if(ok[j])
			{
				if(a[j]>>i&1) ct++;
			}
		}
		if(ct>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;j++)
			{
				if(ok[j])
				{
					if((a[j]>>i&1)==0) ok[j]=0;
				}
			}
		}
	}
	printf("%d",ans);
}
