#include<bits/stdc++.h> 
using namespace std;
int n,x[200010];
char c[200010];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		getchar();
		scanf("%c",&c[i]);
	}
	int l=1,r=n;
	while(l<=r)
	{
		int y=min(x[l],x[r]);
		if(c[l]!=c[r])
		{
			ans+=y; 
		}
		x[l]-=y;
		x[r]-=y;
		if(x[l]<=0)
		{
			l++;
		}
		if(x[r]<=0)
		{
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
