#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
vector<int> e[1000005];
int f;
void dfs(int now,int fa,int st,int a,int b)
{
	if(now==a || now==b)
	f=min(f,st);
	for(int i=0;i<e[now].size();i++)
	{
		int son=e[now][i];
		if(son==fa)
		continue;
		
		dfs(son,now,st+1,a,b);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0); 
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	int mx=1e18;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				continue;
				for(int x=1;x<=n;x++)
				{
					if(x==i || x==j)
					continue;
					f=1e18;
					dfs(x,-1,0,i,j);
					mx=min(mx,f);
				}
			}
		}
		cout<<mx<<"\n";
	}
	
	
	return 0;
}
