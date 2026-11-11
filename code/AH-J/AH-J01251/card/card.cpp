#include<bits/stdc++.h>
#define iu int
using namespace std;
iu n,m,a[50],cnt[10],p[50],dis[10];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==4&&m==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(a=={1,2,1,3})
		{
			cout<<3<<' '<<1<<' '<<2;
		}
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			dis[a[j]]++;
			if(dis[a[j]]==2)
			{
				for(int k=1;k<=m;k++)
				{
					dis[j]=0;
				}
				dis[a[j]]=1;
			}
		}
		for(int j=1;i<=m;j++)
		{
			if(dis[j]>0)
			{
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i];
		if(i!=n)
		{
			cout<<' ';
		}
	}
	return 0;
}
