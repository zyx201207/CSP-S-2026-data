#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long head[N];
long long nxt[N<<1];
long long to[N<<1];
long long val[N<<1];
long long cnt;
long long f[N];
long long s;
long long c,n,m,d,q1;
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
void add(long long u,long long v,long long w)
{
	to[cnt]=v;
	val[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt++;
}
void dijkstra()
{
	f[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		long long u=q.top().second;
		if(f[u]!=q.top().first)
		{
			q.pop();
			continue;
		}
		q.pop();
		for(int i=head[u];~i;i=nxt[i])
		{
			long long v=to[i];
			long long w=val[i];
			if(f[v]>f[u]+w)
			{
				f[v]=f[u]+w;
				q.push(make_pair(f[v],v));
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof head);
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q1;
	
	return 0;
}
