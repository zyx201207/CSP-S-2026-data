#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],s[N][40],cnt[40],vis[N],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k=a[i];
		vis[i]=1;
		for(int j=1;j<=30;j++)
		{
			if((k>>(j-1))&1)
			{
				s[i][j]=1;
				cnt[j]++;
			}
		}
	}
	for(int k=30;k>=1;k--)
	{
		if(cnt[k]<m)continue;
		for(int i=1;i<=n;i++)
		{
			if(vis[i] and !s[i][k])
			{
				vis[i]=0;
				for(int j=1;j<=30;j++)
				{
					if((a[i]>>(j-1))&1)
					{
						cnt[j]--;
					}
				}
			}
		}
		ans+=1<<(k-1);
	}
	cout<<ans;
	return 0;
}
