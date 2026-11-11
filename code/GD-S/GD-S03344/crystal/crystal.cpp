#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505000],maxn=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(0));
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for (long long i=a[1];i<=1e18;i++)
	{
		long long  shu=0,hao=m,cha[50050],jx;
		for (long long j=1;j<=n;j++)
		{
			if (a[j]>i)
			{
				break;
			}
			else if (a[j]<=i)
			{
				hao=hao-(i-a[j]);
				if (hao>=0)
				{
					shu++;
				}
				else
				{
					int zhi=0,xu=0;
					for (int k=1;k<=j;k++)
					{
						if (cha[k]==0)
						continue;
						else if (cha[k]>=i-a[j] && cha[k]>zhi)
						{
							zhi=cha[k];
							xu=k;
						}
					}
					if (zhi==0)
					break;
					hao=hao+zhi-a[j];
					cha[xu]=i-a[j];
				}
			}	
		}
		if (maxn<=shu)
			maxn=shu;
		else
	       break;
	}
	cout<<maxn;
	return 0;
}
