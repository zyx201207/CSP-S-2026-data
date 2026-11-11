//∞≤À≥∑ÔªÀ—ß–£ ¡ı‘∂Íª GZ-J00157 
#include<bits/stdc++.h>
using namespace std;
int m,n,i;
long long a[20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
		if(m==n)
		{
			i=2;
			while(i<=n)
			{
				a[i]=(a[i]||a[i-1]);
			}
			cout<<a[n-1];
			return 0;
		}
		if(m==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]>maxx)
				{
					maxx=a[i];
				}
			}
			cout<<maxx;
			return 0;
		}
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;i++)
				if((a[i]||a[j])>maxx)
				{
					maxx=(a[i]||a[j]);
				}
			}
			cout<<maxx;
			return 0;
		}
		if(m==n-1)
		{
			i=2;
			while(i<=n)
			{
				a[i]=(a[i]||a[i-1]);
			}
			cout<<a[n-1];
			return 0;
		}
	return 0;
}
