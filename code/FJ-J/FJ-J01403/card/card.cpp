#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sz[300005],f[500005],xsz[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(xsz,0,sizeof(xsz));
		cnt=0;
		for(int j=i;j<=n;j++)
		{
			xsz[a[j]]++;
			if(xsz[a[j]]==1)
			{
				cnt++;
			}
			else{
				for(int x=1;x<=cnt;x++)
				{
					if(f[x]==a[j])
					{
						for(int l=x;l<=cnt;l++)
						{
							xsz[f[l]]--;
						}
						cnt=x;
						break;
					}
				}
			}
			f[cnt]=a[j];
		}
		for(int j=1;j<=m;j++)
		{
			sz[j]+=xsz[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sz[i]<<" ";
	}
	return 0;
}
