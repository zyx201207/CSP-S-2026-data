#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int n,r,m,a[N],vis[N],ans[N],maxx=-N;
struct node
{
	int first,second;
}v[N];
bool cmp1(node p,node q)
{
	return p.first>q.first;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(v[a[i]].first!=0 && v[a[i]].second==0)	v[a[i]].second=i,r++;
		if(v[a[i]].first==0)	v[a[i]].first=i,r++,maxx=max(maxx,i);
		if(r==(m*2))	break;
	}
	sort(v+1,v+1+m,cmp1);
	
	for(int i=1;i<=n;i++)		//i是当前第几局游戏   第几局游戏发牌就从第几张发 
	{
		for(int j=1;j<=m;j++)
		{
			if(i>v[j].second)
			{
				for(int k=v[j].first;k<=n;k++)
				{
					ans[a[k]]++;
				} 
				break;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
} 

/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;i++)
		{
			if(vis[a[j]]!=0)
			{
				memset(vis,0,sizeof(vis));
			}
			vis[a[j]]=1;
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i]!=0)
			{
				ans[i]++;
			}
		}
	}
*/
