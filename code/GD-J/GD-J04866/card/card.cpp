#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int mzong[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2) 
	{
		cout<<n<<' '<<n;
		return 0;
	}
	else{
		for(int i = 1;i<=n;i++)
		{
			int m1[300005]={};
			for(int j = i;j<=n;j++)
			{
				if(m1[a[j]]==0)
				{
				m1[a[j]]++;
				}else
				{
					for(int k = j-1;k>=i;k--)
					{
						if(a[k]!=a[j]) m1[a[k]]--;
						else
						{
							m1[a[k]]--;
							continue;
						}
					}
				}
			}
			for(int l = i;l<=m;l++) mzong[l]+=m1[l];
		}
		for(int i = 1;i<=m;i++)
		{
			cout<<mzong[i]<<' ';
		}
	}
	return 0;
}
