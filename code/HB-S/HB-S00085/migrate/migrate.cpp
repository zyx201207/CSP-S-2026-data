#include <iostream>
#include <queue>
using namespace std;
long long c,t,n,d,x[2000005],dis[2000005],cnt[2000005],ans;
bool vis[2000005];
struct node{
	long long v,w;
};
bool operator<(node a,node b){return a.w>b.w;}
priority_queue<node> q;
void dijsktra(int st)
{
	for(int i=1;i<=n;i++) dis[i]=8e18+5;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) cnt[i]=0;
	dis[st]=0;
	cnt[st]=1;
	while(!q.empty()) q.pop();
	q.push({st,0});
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		for(int i=u+1;i<=n;i++)
		{
			if(x[i]-x[u]>d) break;
			if(dis[u]+1<dis[i])
			{
				dis[i]=dis[u]+1;
				cnt[i]=cnt[u];
				q.push({i,dis[i]});
			}
			else if(dis[u]+1==dis[i]) cnt[i]+=cnt[u]; 
		}
	}
	/*cout<<'$'<<st<<'\n';
	for(int i=st;i<=n;i++) cout<<dis[i]<<' ';
	cout<<'\n';
	for(int i=st;i<=n;i++) cout<<cnt[i]<<' ';
	cout<<'\n';*/
	for(int i=st+1;i<=n;i++)
		if(cnt[i]==2)
		{
			ans++;
			//cout<<'*'<<st<<' '<<i<<'\n';
		} 
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		ans=0;
		for(int i=1;i<=n;i++) dijsktra(i);
		cout<<ans<<'\n';
	}
	return 0;
}
