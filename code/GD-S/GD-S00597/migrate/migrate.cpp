#include<bits/stdc++.h>
using namespace std;
int n,x[200006];
struct node
{
	int minfar,cnt;
}dp[200005];
int c,t,d;
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			dp[i].cnt=0;
			dp[i].minfar=1e9;
		}
		dp[0].cnt=0;
		dp[1].cnt=1;
		int x=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=max(i-d,0);j<i;j++)
			{
				if(dp[j].minfar+1==i/j)
				{
					cout<<1;
					dp[i].cnt+=dp[j].cnt;
					dp[i].minfar=dp[j].minfar+1;
				}
				cout<<1;
			}
			if(dp[i].cnt==2) x++;
		}
		if(x<=n) cout<<x<<'\n';
		else cout<<0;
	}
} 
