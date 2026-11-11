#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<vector<int>> l,t;
vector<int> vis,ss,w;
bool fd(int i,int s)
{
	for(auto p:l[i])
	{
		if(p==s)
			return 1;
	}
	return 0;
}
long long dfs(int s,int e,long long sum,vector<int> ss)
{
	for(auto p:ss)
	{
		for(auto q:l[p])
		{
			if(!vis[q])
			{
				vis[q]=1;
				vector<int> v;
				for(int i=1;i<=n;i++)
				{
					if(fd(i,s))
					{
						if(fd(i,e))	return sum+w[s]+t[i][s];
						v.push_back(i);
					}
				}
				return dfs(q,e,sum+w[s]+t[p][s],v);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vis.assign(n+1,0);
	w.assign(m+1,{});
	l.assign(n+1,{});
	t.assign(n+1,vector<int>(m+1));
	int k,id,s,e,weigh;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>id>>weigh;
			l[i].push_back(id);
			t[i][id]=weigh;
		}
	}
	while(q--)
	{
		cin>>s>>e;
		for(int i=1;i<=n;i++)	vis[i]=0;
		ss.clear();
		vis[s]=1;
		bool tf=0;
		for(int i=1;i<=n;i++)
		{
			if(fd(i,s))
			{
				if(fd(i,e))
				{
					cout<<"0\n";
					tf=1;
					break;
				}
				ss.push_back(i);
			}
		}
		if(!tf)	cout<<dfs(s,e,0,ss)<<"\n";
	}
	return 0;
}
