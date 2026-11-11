#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n,m,a[MAXN],ans[300005];
int csx[300005];
int find(int x,int y)
{
	for(int i=y-1;i>=1;i--)
	{
		if(a[i]==x)
		{
			return i;
		}
	}
}
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
			if(csx[a[j]]==0)
			{
				csx[a[j]]++;
			}
			else
			{
				for(int z=find(a[j],j)+1;z<=j-1;z++)
				{
					csx[a[z]]=0;
				}
			} 
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=csx[j];
		}
		for(int j=1;j<=m;j++)
		{
			csx[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
