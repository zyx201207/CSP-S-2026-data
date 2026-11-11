#include<bits/stdc++.h>
using namespace std;
vector <int> book[505];
int a[1005][2],b[1005][2];
int t[1005];
int res=0x3f3f3f3f;
void dfs(int s,int e,int step)
{
	if(s==e)
	{
		res=min(res,step);
		return ;
	}
	int len=book[s].size();
	for(int i=0;i<len;i+=2)
	{
		dfs(book[s][i],e,step+book[s][i+1]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>t[i];
	if(7<=c && c<=11)
	{
		for(int i=1;i<=n;i++)
		{
			int t;
			cin>>t;
			for(int j=1;j<=t;j++)
			{
				int u,v;
				cin>>u>>v;
				if(a[u][0]!=0)
				{
					book[i].push_back(a[u][0]);
					book[i].push_back(b[u][0]+v);
					book[a[u][0]].push_back(i);
					book[a[u][0]].push_back(b[u][0]+v);
					a[u][1]=i;
					b[u][1]=v;
				}
				else
				{
					a[u][0]=i;
					b[u][0]=v;
				}
			}
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			int sum=t[l]+t[r];
			res=0x3f3f3f3f;
			dfs(a[l][0],a[r][0],b[l][0]+b[r][0]);
			if(a[l][1]!=0)
				dfs(a[l][1],a[r][0],b[l][1]+b[r][0]);
			if(a[r][1]!=0)
				dfs(a[l][0],a[r][1],b[l][0]+b[r][1]);
			if(a[l][1]!=0 && a[r][1]!=0)
				dfs(a[l][1],a[r][1],b[l][1]+b[r][1]);
			cout<<sum+res<<endl;
		}
	}
	if(12<=c && c<=19)
	{
		for(int i=1;i<=n;i++)
		{
			int t;
			cin>>t;
			for(int j=1;j<=t;j++)
			{
				int u,v;
				cin>>u>>v;
				if(a[u][0]!=0)
				{
					book[i].push_back(a[u][0]);
					book[i].push_back(a[u][2*v]);
					book[a[u][0]].push_back(i);
					book[a[u][0]].push_back(2*v);
				}
				int w=0;
				while(a[u][w]!=0)
					w++;
				a[u][w]=i;
				b[u][w]=v;
			}
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			res=0x3f3f3f3f;
			int sum=t[l]+t[r];
			int ta=0;
			while(a[l][ta]!=0)
			{
				int tb=0;
				while(a[r][tb]!=0)
				{
					dfs(a[l][ta],a[r][tb],b[l][ta]+b[r][tb]);
					tb++;
				}
				ta++;
			}
			cout<<sum+res<<endl;
		}
	}
	return 0;
}

/*
9 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
1 3
*/
