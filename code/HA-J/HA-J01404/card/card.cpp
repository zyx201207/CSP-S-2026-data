#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int ans[300010];
int cnt[300010],x[300010];
int l,r,num[500010];
int len;
bool live[500010];
int N;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++)
//	{
//		ans[a[i]]=max(ans[a[i]],n-i+1);
//	}
	for(int j=n;j>=1;j--)
	{
		memset(live,0,sizeof live);
		memset(x,0,sizeof x);
		for(int i=j;i<=n;i++)
		{
			if(live[a[i]]==0)
			{
				live[a[i]]=1;
			}
			else
			{
				int l=x[a[i]],r=i-1;
				if(!live[i])continue;
				for(int k=a[i]+1;k<=r;k++)
					live[i]=0;
			}
			x[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
//			cout<<live[i]<<' ';
			if(live[i])ans[i]++;
		}
//		cout<<endl;
	}
	for(int j=1;j<=m;j++)
		cout<<ans[j]<<' ';
	return 0;
}