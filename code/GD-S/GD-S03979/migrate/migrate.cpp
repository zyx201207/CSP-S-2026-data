#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,inf=1e9;

int n;
ll d,a[N];
ll cnt[N],dis[N];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	for(int st=1;st<=n;st++)
	{
		for(int i=st;i<=n;i++)
		{
			dis[i]=inf;
			cnt[i]=0;
		}
			
		queue<pair<int,int>>q;
		q.push({st,0});
		dis[st]=0;
		while(!q.empty())
		{
			int u=q.front().first,dd=q.front().second;
			q.pop();
		
			if(dd>dis[u]) continue;
			if(dd==dis[u])
				cnt[u]++;
			for(int v=u+1;v<=n;v++)
			{	
				if(a[v]-a[u]>d)break;
				
				if(dis[v]<dd+1)continue;
				if(dis[v]>dd+1)
				{
					dis[v]=dd+1;	
					cnt[v]=0;
				}
					
				q.push({v,dd+1});
			}
		}
		for(int i=st+1;i<=n;i++)
		{
			if(cnt[i]==2)ans++;		
		}
	}
	
	cout<<ans<<"\n";
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);	
	
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		solve();	
	}	
	return 0;
}
/*
0 1
6 12
-10 -6 -2 2 6 10
*/
