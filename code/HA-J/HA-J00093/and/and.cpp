#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=200007,INF=0x3f3f3f3f;
int num[M],cardout[M],mm[M];
signed main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","r",stdout);
	int n,m,nlong=1,mr=0,l;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cardout[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)num[j]=INF;
		nlong=1;
		num[i]=cardout[i];
		for(int j=i+1;j<=n;j++)
		{
			mr=0;
			for(int k=1;k<=nlong;k++)
			{
				if(num[k]==cardout[j])
				{
					num[k]=INF;
					l=nlong;
					for(int f=k;f<=l;f++){num[f]=INF;nlong--;}
					mr=1;
				}
			}
			if(mr==0)
			{
				nlong++;
			}
			num[nlong]=cardout[j];
		}	
		for(int j=i;j<=n;j++)if(num[j]!=INF)mm[j]++;
	}
	for(int i=1;i<=m;i++)cout<<mm[i]<<" ";
	return 0;
}

