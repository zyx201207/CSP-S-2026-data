#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000006;
bool vis[N];
int arr[N];
int c,t,n,d;
int cnt=0,ans=0;
int minn=2e18+10;
void dfs(int now,int dis,int pos)
{
	//if(cnt>2) return ;
	if(dis>minn) return ;
	if(now==pos)
	{
		if(dis==minn) cnt++;
		if(dis<minn)
		{
			cnt=1;
			minn=dis;
		}
		return ;
	}
	for(int i=now+1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(abs(arr[now]-arr[i])<=d)
		{
			vis[i]=1;
			dfs(i,dis+1,pos);
			vis[i]=0;
		}
		else break;
	}
	for(int i=now-1;i>=1;i--)
	{
		if(vis[i]) continue;
		if(abs(arr[now]-arr[i])<=d)
		{
			vis[i]=1;
			dfs(i,dis+1,pos);
			vis[i]=0;
		}
		else break;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0,cnt=0;
		for(int i=1;i<=n;i++) cin>>arr[i];
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				if(u==v) continue;
				vis[u]=1;
				minn=2e18+10;
				cnt=0;
				dfs(u,0,v);
				vis[u]=0;
				if(cnt==2) 
				{
					ans++;
					//cout<<u<<' '<<v<<' '<<minn<<endl;
				}
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
