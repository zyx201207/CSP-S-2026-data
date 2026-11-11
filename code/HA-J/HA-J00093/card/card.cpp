#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=200007,INF=0x3f3f3f3f;
int num[M],cardout[M],mm[M],pp[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m,nlong=1,mr=0,l;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cardout[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){num[j]=cardout[j];}
		for(int j=i;j<=n-1;j++)
		{
			for(int k=i+1;k<=n;k++)
			{
				if(num[j]==num[k])
				{
					for(int f=j;f<=k-1;f++)
					{
						num[f]=INF;
					}
				}
			}
		}
		for(int j=i;j<=n;j++)if(num[j]!=INF)mm[i]++;
	}
	for(int i=1;i<=m;i++)cout<<mm[i]<<" ";
	return 0;
}

