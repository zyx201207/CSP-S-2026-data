#include<bits/stdc++.h>
using namespace std;

long long x[1000005];

int c,t,n;
long long d;
map<pair<int,int>,pair<int,int>> mp;

pair<int,int> dfs(int u,int v)
{	
	if(mp.count({u,v})) return mp[{u,v}];
	if(x[v]-x[u]<=d) return {1,1};
	pair<int,int> ans={0,-1};
	pair<int,int> cl;
	for(int i=u+1;i<v && x[i]-x[u]<=d;i++)
	{
		cl=dfs(i,v);
		if(ans.second==-1) ans=cl;
		else
		{
			if(cl.second==ans.second)
			{
				ans.first+=cl.first;	
			}
			else if(cl.second<ans.second) ans=cl;
		}
	}
	ans.second++;
	mp[{u,v}]=ans;
	return ans;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	
	int ans;
	pair<int,int> re;
	
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=0;i<n;i++)
			cin>>x[i];
		mp.clear();
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				re=dfs(i,j);
				if(re.first==2) ans++;
			}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
