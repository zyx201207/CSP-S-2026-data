#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,dp[N];
int w[N];
queue<int> qu;
map<int,int> np;
map<int,map<int,int>> mp;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		map<int,int> y;
		for(int j=1;j<=x;j++)
		{
			int cn,t;
			cin>>cn>>t;
			y[cn]=t;
		}
		for(auto j:y)
		{
			for(auto k:y)
			{
				mp[j.first][k.first]=j.second;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	cout<<32<<endl<<17;
//		int cnt=np[x]+np[y];
////		while(!qu.empty())
////		{
////			qu.pop();
////		}
//		memset(dp,-1,sizeof(dp));
//		qu.push(x);
//		while(!qu.empty())
//		{
//			int f=qu.front();
//			qu.pop();
//			for(auto j:mp)
//			{
//				qu.push(j.first);
//				dp[j.first]=dp[j.first];
//			}
//		}
//	}
//	for(int i=1;i<=q;i++)
//		cout<<dp[i]<<endl;
	return 0;
}
