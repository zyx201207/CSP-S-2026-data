#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,M=1e9,b[100000],x,y;
vector<int>a[10000]; 
void dfs(int r)
{
	if(r==n)
	{
		int ss,c[1000],f[1000],ans[1000],Ma=0;
		queue<int>q;
		for(int i=1;i<=n;i++,f[i]=0,ans[i]=0)
			if(b[i])
				c[++ss]=i,q.push(i);
		if(ss==3 && a[c[1]][c[2]]==0 && a[c[3]][c[2]]==0 && a[c[1]][c[3]]==0)
			return ;
		while(!q.empty())
		{
			int xx=q.front();
			q.pop();
			if(f[xx]==1)
				continue;
			f[xx]=1;
			for(int i=0;i<a[xx].size();i++)
			{
				if(f[a[xx][i]]==0)
				{
					ans[a[xx][i]]=ans[xx]+1;
					q.push(a[xx][i]);
				}
			}
		}
		for(int i=1;i<=n;i++)
			Ma=max(Ma,ans[i]);
		M=min(M,Ma);
		return ;
	}
	b[r]=1;
	dfs(r+1);
	b[r]=0;
	dfs(r+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		M=1000000;
		cin>>n>>m;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(0);
		cout<<M<<endl;
	}
	
	return 0;
}


