#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[50],w[200005],le,ans;
bool f;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int x=a[i],j=0;
		while(x)
		{
			c[j]+=x%2;
			x>>=1;
			j++;
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(c[i]>=m)
		{
			ans+=1<<i;
			if(!f)
			{
				le=0;
				for(int j=1;j<=n;j++)
				{
					if((a[j]>>i)%2)
					{
						w[++le]=a[j]; 
					}
				}
				memset(c,0,sizeof(c));
				for(int j=1;j<=le;j++)
				{
					int x=w[j],k=0;
					while(x)
					{
						c[k]+=x%2;
						x>>=1;
						k++;
					}
				}
				f=1;
			}
			else
			{
				n=0;
				for(int j=1;j<=le;j++)
				{
					if((w[j]>>i)%2)
					{
						a[++n]=w[j]; 
					}
				}
				memset(c,0,sizeof(c));
				for(int j=1;j<=n;j++)
				{
					int x=a[j],k=0;
					while(x)
					{
						c[k]+=x%2;
						x>>=1;
						k++;
					}
				}
				f=0;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
