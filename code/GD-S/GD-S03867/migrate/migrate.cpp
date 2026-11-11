#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N=310;
int c,T,n,d,x[N],cnt=0;
vector<int> G[N];
map<int,int> mp;
void dfs (int u,int tar,int dis)
{
	if (u==tar) 
	{
		cnt++;
		mp[dis]++;
		return ;
	}
	for (int v:G[u])
	{
		dfs(v,tar,dis+1);
	}
}
bool check (int x,int y)
{
	mp.clear();
	cnt=0;
	vector<int> path;
	dfs(x,y,0);
	if (mp.size()==0) return 0;
	if (mp.begin()->second==2) return 1;
	return 0;
}
signed main  ()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while (T--)
	{
		int ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i],G[i].clear();
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (x[j]-x[i]<=d) 
				{
					G[i].push_back(j);
				}
				else 
				{
					break;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (check(i,j)) 
				{
					ans++;
//					cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<ans<<endl; 
	} 
	return 0;
} 
