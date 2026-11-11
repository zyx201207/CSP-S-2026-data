#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,q;
struct node{
	int cnt;
	int val;
};
int p=2*1e18;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	for(int t=0;t<q;t++)
	{
		int n,d;
		int a[5005];
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		node dp[5005];	
		int ans=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=0;i<=5005;i++)
			{
				dp[i]={0,p};
			}
			dp[k]={0,0};
			for(int i=k+1;i<=n;i++)
			{
				for(int j=i-1;j>=k;j--)
				{
					if(a[i]-a[j]<=d)
					{
						if(dp[i].val>dp[j].val+1) 
						{
							dp[i].val=dp[j].val+1;
							dp[i].cnt=1;
						}
						else if(dp[i].val==dp[j].val+1) 
						{
							dp[i].cnt+=dp[j].cnt;
						}					
					}
				}
//				cout<<dp[i].cnt<<" "<<dp[i].val<<endl;				
			}
			for(int i=1;i<=n;i++)
			{
				if(dp[i].cnt==2) ans++;
			}
//			cout<<"k"<<k<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}

