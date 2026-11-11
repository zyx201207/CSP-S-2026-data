#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],e[300005],t=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int flag = 0;
			for(int k=t-1;k>=1;k--)
			{
				if(e[k] == a[j])
				{
					flag = k;
					break;
				}
			}
			if(flag == 0)
			{
				e[t] = a[j];
				t++;
			}
			else
			{
				t = flag+1;
			}
		}
		for(int j=1;j<t;j++)
		{
			ans[e[j]]++;
		}
		memset(e,0,sizeof(e));
		t = 1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
