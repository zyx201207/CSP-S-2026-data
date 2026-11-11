#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000006],ans[1000006];
bool vis[1000006];
int c[1000006];

int main()
{
	
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1;
		memset(0,0,sizeof vis);
		memset(0,0,sizeof c);
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])vis[a[j]]=1;
			else
			{
				while(c[l]==a[j])
				{
					vis[c[l]]=0;
					l--;
				}
				l--;
			}
			c[l]=a[j];
			l++;
		}
		for(int i=1;i<=l;i++)ans[c[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;	
}
