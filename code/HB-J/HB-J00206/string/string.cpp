#include<bits/stdc++.h>
using namespace std;
int n=0,x[200010];
//long long cnt=0;
char y[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	/*for(int i=0;i<n;i++)
	{
		cnt+=x[i];
	}*/
	int g=n-1;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(i==g||i>g)
		break;
		if(x[i]>x[g])
		{
			if(y[i]!=y[g])
			{
				//printf("d003");
				ans+=x[g];
			}
			x[i]-=x[g];
			i--;
			x[g]=0;
			g--;
		}else if(x[i]<x[g])
		{
			if(y[i]!=y[g])
			{
				//printf("d002 %c %c %d "  ,y[i],y[g],i);
				ans+=x[i];
			}
			x[i]=0;
			x[g]-=x[i];
		}else if(x[i]==x[g])
		{
			if(y[i]!=y[g])
			{
				//printf("d001");
				ans+=x[i];
			}
			x[i]=0;
			x[g]=0;
			g--;
		}
	}
	printf("%lld",ans);
	return 0;
}
