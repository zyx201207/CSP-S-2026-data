#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool c[300005]={0},ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		bool c[300005]={0};
		for(int i=j;i<=n;i++)
		{
			if(c[a[i]]==0)
			{
				c[a[i]]=1;
			}
			else
				for(int k=i;k>=1;k--)
					c[a[k]]=0;
		}
		if(c[j])
			cout<<j;
	}
	
}
