#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2100001];
vector<int> a[2000011];
int minn=INT_MAX,cntmin=0;
void dfs(int k,int v,int step)
{
	if(k == v)
	{
		if(step < minn)
		{
			minn = step;
			cntmin=1;
		}
		else if(step == minn)
		{
			cntmin++;
		}
		return ;
	}
	for(int i=0;i<a[k].size();i++)
	{
		dfs(a[k][i],v,step+1);
	}
}
void solve()
{
	cin >> n >> d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x[j]-x[i] <= d) a[i].push_back(j);
			else break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int u=i,v=j;
			dfs(u,v,0);
			if(cntmin == 2) ans++;
			minn=INT_MAX,cntmin=0;
		}
	}
	cout << ans << endl;
	for(int i=1;i<=n;i++) a[i].clear();
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();
	
	
	return 0;
}