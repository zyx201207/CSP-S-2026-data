#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[2000005];
vector<int>e[2000005];
int dfs(int u,int t,int temp,int mina)
{
//	cout<<"dfs:"<<u<<' '<<t<<' '<<temp<<' '<<mina<<endl;
	if(temp>=mina && u!=t)return 0;
	if(u==t)return 1;
	ll sum=0;
	for(auto v:e[u])
	{
		if(v>t)break;
		sum+=dfs(v,t,temp+1,mina);
		if(sum>2)return sum;
	}
	return sum;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;cin>>c>>t;
	for(int _=1;_<=t;_++)
	{
		ll ans=0;
		int n;ll d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i],e[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)e[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				bool bro=0;
				int mina=1,last=i;
				for(int k=i+1;k<=j;k++)
				{
					if(a[k]-a[last]>d)
					{
						last=k-1;
						if(a[k]-a[last]>d)
						{
							bro=1;
							break;
						}
						mina++;
					}
				}
				if(bro)break;
//				cout<<i<<' '<<j<<' '<<mina<<endl;
				if(dfs(i,j,0,mina)==2)ans++;//,cout<<i<<' '<<j<<' '<<mina<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
