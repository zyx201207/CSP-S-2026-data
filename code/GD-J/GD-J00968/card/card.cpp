#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
long long n,m,a[N],b[M],p[M][2],sum;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum=0;
		memset(p,0,sizeof p);
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]][0]==1)
			{
				for(int x=p[a[j]][1]+1;x<j;x++)
				{
					p[a[x]][0]=0;
				}
			}
			p[a[j]][0]=1;
			p[a[j]][1]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(p[j][0]==1) b[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
}
