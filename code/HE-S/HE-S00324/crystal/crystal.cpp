#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int a[n+2100]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int mid=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
	}
	int sum=ans/n;
	int b[n+100]={0};
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-sum;
        if((a[i]-sum)<0)
        {
        	b[i]=-(a[i]-sum);
		}
	}
	mid=b[1];
	int nn=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<mid)
		{
			mid=b[i];
			nn=i;
		}

	}
	int mmmm=0;
	int zxy=0;
	for(int i=1;i<=n+100;i++)
	{
	    if(zxy>=m)
		{
			break;
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
                int chy=0;
                if(a[j]<a[nn])
                {
                    a[j]+=1;
                    zxy++;
                }
                else
                {
                    chy++;
                }
                if(chy>n)
                {
                    break;
                }

			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]=a[nn])
		{
			mmmm+=1;
		}
	}
	cout<<mmmm-1;
	return 0;
}
