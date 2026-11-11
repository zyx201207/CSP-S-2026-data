#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			int c[505]={},cnt=1;
			for(int j=i;j<=n;j++)
			{
				for(int z=1;z<cnt;z++)
				{
					if(c[z]==a[j]) cnt=z;
				}
				c[cnt++]=a[j];
			}
			for(int j=1;j<cnt;j++)
			{
				ans[c[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else 
	{
		for(int i=1;i<=m;i++) cout<<n<<" ";
	}
	return 0;
}
