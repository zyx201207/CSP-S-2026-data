#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int INF=0x3f3f3f3f;
int c,t;
int n,d;
int a[N];
int dp[N];
vector<int> ans[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++) dp[j]=INF,ans[j].clear();
			dp[i]=0;
			ans[i].push_back(i);
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j-1;a[j]-a[k]<=d&&k>=i;k--)
				{
//					cout<<"**"<<k<<'\n';
					if(dp[j]>dp[k]+1)
					{
						ans[j].clear();
						for(int f=1;f<=ans[k].size()&&ans[j].size()<=3;f++) ans[j].push_back(k);
						dp[j]=dp[k]+1;
					}
					else if(dp[j]==dp[k]+1)
					{
						for(int f=1;f<=ans[k].size()&&ans[j].size()<=3;f++) ans[j].push_back(k);
					}
				}
//				cout<<i<<" "<<j<<" "<<ans[j].size()<<'\n';
				if(ans[j].size()==2) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
