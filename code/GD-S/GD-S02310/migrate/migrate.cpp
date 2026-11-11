#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000006];
vector<int>road[2000006];
int sum=0;
int have=0;
int minn=INT_MAX;
vector<int>qqq;
void dfs(int x,int y,int zou)
{
	if (x==y)
		{
		minn=min(minn,zou);
		qqq.push_back(zou);
		return;
		}
	if (zou>minn)return;
	for (auto i:road[x])
		dfs(i,y,zou+1);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--)
		{
		sum=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)cin>>x[i];
		for (int i=1;i<=n;i++)road[i].clear();
		for (int i=1;i<=n;i++)
			{
			int ans=x[i]+d;
			for (int j=i+1;j<=n;j++)
				{
				if (x[j]>ans)break;
				road[i].push_back(j);
				}
			}
//		for (int i=1;i<=n;i++)
//			{
//			for (auto j:road[i])cout<<j<<' ';
//			cout<<endl;
//			}
		for (int i=1;i<n;i++)
			{
			for (int j=i+1;j<=n;j++)
				{
				have=0;
				qqq.clear();
				minn=INT_MAX;
				dfs(i,j,0);
				for (auto k:qqq)
					{
					have+=(k==minn);
					if (have>2)break;
					}
				sum+=(have==2);
//				cout<<i<<' '<<j<<' '<<have<<endl;
				}
			}
		cout<<sum<<endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

