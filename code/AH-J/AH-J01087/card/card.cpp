#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[500010],ans[500010];
int a[500010],s[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++)
		{
			f[a[j]]++;
			if(f[a[j]]==2)
			{
				int k=0;
				for(k=j-1;k>=n-i+1;k--)
				{
					s[k]=1;
					if(a[k]==a[j]&&s[k]==0)
					{
						break;
					}
				}
				f[a[j]]=1;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(s[j]==0)
			{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
