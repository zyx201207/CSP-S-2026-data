#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
int dp[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			cin>>x[i];
		}
		dp[0]=0;
		dp[1]=1;
		for(int i=2;i<=n;++i)
		{
			dp[i]=0;
			int maxx=-1;
			for(int j=1;j<=d;++j)
			{
				if(i-j>=0)
				{
					dp[i]+=dp[i-j];
				}
			}
		}
		int cnt=0;
		//cout<<"dp:";
		for(int i=2;i<=n;++i)
		{
			if(dp[i]==2)cnt++;
			//cout<<dp[i]<<" "; 
		}
		cout<<cnt<<"\n";
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
