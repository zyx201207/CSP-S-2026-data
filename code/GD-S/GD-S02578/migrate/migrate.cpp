#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int c,t;
int n,d,x[2000001];
int mp[1001];
inline void dfs(int st,int ed,int res)
{	if(x[st]==x[ed])
	{	mp[res]++;
		return;
	}
	for(int i=1;i<=ed-st;i++)
		if(x[st+i]-x[st]<=d)
		{	dfs(st+i,ed,res+1);
		}
}
signed main()
{	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{	cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(x[1]<0)
		{	int add=x[1];
			for(int i=1;i<=n;i++)
				x[i]+=add;
		}
		for(int u=1;u<n-2;u++)
			for(int v=u+3;v<=n;v++)
			{	memset(mp,0,sizeof(mp));
				dfs(u,v,1);
				int pt=0;
//				for(int i=1;i<=9;i++)
//					cout<<mp[i]<<"  ";
//				cout<<"\n";
				while(mp[pt]==0)
					pt++;
				if(mp[pt]==2)
					ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
//I'll have to get back to whk now...
