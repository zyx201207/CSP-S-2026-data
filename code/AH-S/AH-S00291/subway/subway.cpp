#include<bits/stdc++.h>
using namespace std;
int o[500005],f[500005],bj[500005],c,n,m,k,t;
struct dj
{
	int x,y;
};
vector<dj>a[100005];
void cmp(int rz,int cz)
{
	memset(f,0x3f,sizeof(f));
	memset(bj,0,sizeof(bj));
	f[rz]=0;
	priority_queue<pair<int,int>>q;
	q.push(make_pair(0,rz));
	while(!q.empty())
	{
		int t=q.top().second;
		q.pop();
		if(bj[t])
		{
			continue;
		}
		bj[t]=1;
		for(auto i:a[t])
		{
			int x=i.x,y=i.y;
			if(f[x]>f[t]+y)
			{
				f[x]=f[t]+y;
				q.push(make_pair(-f[x],x));
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>k>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>o[i];
	}
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>x>>y;
			a[m+i].push_back({x,y});
			a[x].push_back({m+i,y});
		}
	}
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		cmp(x,y);
		cout<<f[y]+o[x]+o[y]<<endl;
	}
}
