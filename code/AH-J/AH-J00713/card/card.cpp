#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],ans[300005],c[500005],f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]])
			{
				c[f[a[j]]]--;
				c[j]++;
			}
			c[j]++;
			c[j+1]--;
			f[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			c[j]+=c[j-1];
			if(c[j]==1)ans[a[j]]++;
		}		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
