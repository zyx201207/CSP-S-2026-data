#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
ll C,t,n,d;
//priority_queue<pair<ll,ll> > q;
//bool vis[N];
//void add(ll x,ll y,ll val)
//{
//	nxt[tot]=head[x];
//	to[tot]=y;
//	w[tot]=val;
//	head[x]=tot++;
//}
//void dijkstra(ll s)
//{
//	memset(d,0x3f3f3f,sizeof(d));
//	d[s]=0;
//	vis[s]=1;
//	q.push(make_pair(0,s));
//	while(!q.empty())
//	{
//		while(!q.empty()&&vis[q.top().second])
//		{
//			q.pop();
//		}
//		if(q.empty())
//		{
//			break;
//		}
//		ll afo=q.top().second;
//		q.pop();
//		vis[afo]=1;
//		for(int i=head[afo];~i;i=nxt[i])
//		{
//			if(d[to[i]]>d[afo]+w[afo])
//			{
//				d[to[i]]=d[afo]+w[afo];
//				q.push(make_pair(-d[to[i]],to[i]));
//			}
//		}
//	}
//}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--)
	{
		cin>>n>>d;
		ll x[N]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		cout<<n*(n-1)/2<<'\n';
	}
	return 0;
}
