#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
/*int vis2[31];
bool vis3[MAXN][31],anss[MAXN];
vector < int> vis[31];
vector < int> q;*/
int vis2[31];
bool vis[MAXN][31],vis3[MAXN];
int n,m,a[MAXN],l=0,cnt=0,qq=0,ww=0;
int ans=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		while (x)
		{
			if (x&1)
			{
				vis3[i][cnt]=1;
				vis2[cnt]++;
			}
			x=x>>1;
			cnt++;
		}
		l=max(l,cnt-1);
	}
	for (int i=l;i>=0;i--)
	{
		if (vis2[i]>=m)
		{
			qq=vis2[i];
			ww=i;
			break;
		}
	}
	for (int i=ww;i>=0;i++)
	{
		if (qq==m)
		{
			for (int j=0;j<n;j++)
			{
				if (!vis3[j])
				{
					ans=ans&a[j];
				}
			}
		}
		for (int j=0;j<n;j++)
		{
			if (!vis3[j])
			{
				if (!vis[j][i])
				{
					vis3[j]=1;
					qq--;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
GG
for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		int cnt=0;
		while (x)
		{
			if (x&1)
			{
				vis[cnt].push_back(i);
				vis3[i][cnt]=1;
			}
			vis2[cnt]++;
			x=x>>1;
			cnt++;
		}
		l=max(l,cnt-1);
	}
	bool k=0;
	for (int i=l;i>=0;i--)
	{
		if (vis2[i]>=m)
		{
			if (!k&&vis2[i]==m)
			{
				for (int j=0;j<vis[i].size();j++)
				{
					ans=ans&a[i];
				}
				printf("%lld\n",ans);
				return 0;
			}
			if (!k)k=1;
			q.push_back(i);
		}
	}
	if (k==0)
	{
		printf("0\n");
		return 0;
	}
	l=q.size();
	int qwq=q[0];
	for (int i=0;i<vis[q[0]].size();i++)
	{
		anss[vis[q[0]][i]]=1;
	}
	for (int i=1;i<q.size();i++)
	{
		for (int j=0;j<vis[q[0]].size();j++)
		{
//			anss[vis[q[0]][j]]=anss[vis[q[0]][j]]&vis3[vis[q[0]][j]][q[i]];
			if (!vis3[vis[q[0]][j]][q[i]])
			{
				qwq--;
//				anss[vis[q[0]][j]]=0;
			}
		}
		if (qwq<=m)
		{
			for (int i=0)
		}
		else
		{
			for (int j=0;j<vis[q[0]].size();j++)
			{
				if (!vis3[vis[q[0]][j]][q[i]])
				{
					anss[vis[q[0]][j]]=0;
				}
			}
		}
	}
*/
