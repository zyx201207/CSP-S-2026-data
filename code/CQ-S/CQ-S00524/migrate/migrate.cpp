#include<bits/stdc++.h>
using namespace std;
namespace did
{
	const int N=2e6+5;
	int n,d,x[N],path[5005][5005],minn[5005][5005];
	void dfs(int dq,int bx,int sum)
	{
		if(sum<minn[bx][dq]) 
		{
			minn[bx][dq]=sum;
			path[bx][dq]=1;
		}
		else if(sum==minn[bx][dq]) path[bx][dq]++;
		//cout<<bx<<" "<<dq<<" "<<sum<<"\n";
		for(int i=dq+1;i<=n;i++)
		{
			if(x[i]-x[dq]>d) break;
			dfs(i,bx,sum+1);
		}
	}
	int main()
	{
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		int c,t;
		cin>>c>>t;
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					minn[i][j]=1e9;
				}
			}
			memset(path,0,sizeof(path));
			for(int i=1;i<=n;i++) dfs(i,i,0);
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(path[i][j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
}
int main()
{
	did::main();
	return 0;
}
