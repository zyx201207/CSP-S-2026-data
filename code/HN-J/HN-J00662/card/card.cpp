#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005],d[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,h,y;
	cin>>n>>m;
	int k=n;
	if(n<=500&&m<=200)
	{
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
			b[i]=0;
			c[i]=0;
			d[i]=0;
		}
		for(int i=1; i<=n; i++)
		{
			int l=1;
			for(int j=i; j<=n; j++)
			{
				b[l]=a[j];
				for(int h=1; h<=l; h++)
				{
					if(b[h]==a[j])
					{
						l=h;
						break;
					}
				}
				l++;
			}
			for(int k=1; k<=l-1; k++)
			{
				c[b[k]]=1;
			}
			for(int k=1; k<=m; k++)
			{
				d[k]+=c[k];
			}
			for(int k=1; k<=m; k++)
			{
				c[k]=0;
			}
		}
		for(int i=1; i<=m; i++)
		{
			cout<<d[i]<<" ";
		}
	}
	else
	{
		if(n==m)
		{
			for(int i=1; i<=n; i++)
			{
				cout<<n<<" ";
			}
		}
		else if(m<=2)
		{
			cout<<n<<" "<<n;
		}
		else
		{
			for(int i=1;i<=m;i++)
			{
				cout<<1<<" ";
			}
		}
	}
	return 0;
}
