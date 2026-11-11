#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		int l=1,r=1;
		for(int j=i;j<=n;j++)
		{
			int flag=0;
			for(int x=l;x<r;x++)
				if(b[x]==a[j])
				{
					flag=x;
					break;
				}
			if(!flag)
				b[r++]=a[j];
			else
			{
				r=flag;
				b[r++]=a[j];
			}
		}
		for(int j=l;j<r;j++)
			ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
