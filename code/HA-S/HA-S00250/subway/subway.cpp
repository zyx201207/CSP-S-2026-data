#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
struct nodes{
	long long x,y;
};
long long c,n,m,kkk,ci;
vector<node> e[500002];
long long vis[100002];
long long d[100002];
long long w[100002];
nodes ji[100002];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
void diji(long long x,long long s)
{
	for(int i=1;i<=n;i++) d[i]=999999999999;
	d[s]=0; q.push({0,s});
	while(!q.empty())
	{
	   	auto os=q.top();q.pop();
	   	long long k=os.second;
	   	if(k==x){
	   		cout<<d[x]-w[x]<<endl;
	   		break;
	   	}
	   	if(vis[k]) continue;
	   	vis[k]=1;
	   	for(auto ed:e[k])
	   	{
	   		long long v=ed.v,w=ed.w; 
	   		if(d[v]>d[k]+w)
	   		{
	   			d[v]=d[k]+w;
	   			q.push({d[v],v});
	   		}
	   	}
    }
	while(!q.empty()) q.pop();
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>m>>n>>kkk>>ci;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		long long k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			long long v,zhi;cin>>v>>zhi;
			e[i].push_back({v,zhi+w[i]});
		}
	}
	for(int i=1;i<=ci;i++)
	{
		cin>>ji[i].x>>ji[i].y;
		diji(ji[i].x,ji[i].y);
	}
	return 0;
}
