#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
long long a[500010],b[500010],c[500010],d[500010];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int t=n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		c[i]+=x;
	}
	while(t--)
	{
		int tg=0;
		for(int i=1;i<=n;i++)
			a[i]=0;
		for(int i=1;i<=n;i++)
			a[i]+=c[i+tg];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i]==a[j])
				{
					for(int k=i;k<=j-1;k++)
						a[k]=0;
				}
		for(int i=1;i<=n;i++)
		{
			int dxb=1;
			if(a[i]!=0)
			{
				int fx=a[i];
				d[dxb]+=fx;
			}
			dxb++;
		}
		for(int i=1;i<=n;i++)
		{
			int lg=d[i];
			b[lg]++;
		}
		tg++;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	return 0;
}

