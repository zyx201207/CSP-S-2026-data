#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5005;
ll c,t,n;
ll x[N],d,ans,sp[N];
ll vis[N];
vector<int>l[N];
void dfs(int nw,int stp)
{
	if(stp<sp[nw])
	{
		vis[nw]=1;
		sp[nw]=stp;
	} 
	else if(stp==sp[nw])vis[nw]++;
	else return;
	for(int i:l[nw])
	{
		dfs(i,stp+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)l[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]>d)break;
				l[i].push_back(j); 
			}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(sp,0x3f,sizeof(sp));
			dfs(i,0);
			for(int j=1;j<=n;j++)
			{
//				cout<<i<<" "<<j<<" "<<vis[j]<<endl;
				if(vis[j]==2)ans++;
				
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
