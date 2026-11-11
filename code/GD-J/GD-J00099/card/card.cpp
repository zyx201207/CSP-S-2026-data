#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500006],b[500006],c[500006];
long long num=1,ans=1,d[500006],sum;
bool p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	p=true;
	for(int i=1;i<=n;i++)
	{
		int ai;
		cin>>ai;
		a[i]=ai;
	}
	for(int i=1;i<=n;i++)
	{
		c[a[i]]++;
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=n;i++)
		{
			num=1;
			for(int j=i;j<=n;j++)
			{
				if(c[a[j]]>1)
				{
					c[a[j]]--;
					sum=a[j];
					p=false;
					continue;
				}
				if(p==false&&sum==a[j])
				{
					c[a[j]]++;
					p=true;
					b[num]=a[j];
					num++;
				}
				else if(p==true)
				{
					b[num]=a[j];
					num++;
				}
				if(b[num]==k)
				{
					d[k]++;
					break;
				}
			}
			
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}

	return 0;
}
