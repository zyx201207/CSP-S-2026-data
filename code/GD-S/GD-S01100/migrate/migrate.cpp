#include<bits/stdc++.h>
const int N=4e3+10;
using namespace std;
int n,m,t,c;
long long d,ans,h[N],x[N],dp[N];
vector<int> g;
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			int step=0,now=i;
			for(int j=1;j<=n;j++) dp[j]=0;
			for(int j=1;j<=n;j++) h[j]=0;
			g.clear();
			g.push_back(i);
			for(int j=i+1;j<=n;j++)
			{
				if(abs(x[j]-x[now])>d)
				{
					g.push_back(j-1);
					now=j-1;
				}
				int oo=j+1;
				if(g.size()>=2) oo=g[g.size()-2]+1;
				else dp[j]=1;
				int ll=lower_bound(x+1,x+1+n,x[j]-d)-x;
				ll=min(ll,now+1);
				ll=max(ll,oo);
				dp[j]=h[now]-h[ll-1];
				if(g.size()<=1) dp[j]=max(dp[j],(long long)1);
				/*
				for(int kk=oo;kk<=now;kk++)
				{
					if(abs(x[j]-x[kk])<=d) dp[j]+=dp[kk];
				} */
				h[j]=h[j-1]+dp[j];
				if(dp[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
