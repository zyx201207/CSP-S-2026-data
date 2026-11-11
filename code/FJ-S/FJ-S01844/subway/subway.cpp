#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using pii=pair<int,int>;
const int N = 5e5+10;
int c,n,m,d,p,x,y;
int w[N],dd[N],st[N],s[N],z[N],q[N];
struct as{
	int node,w,txt;
};
vector<as>v[N];
map<int,int>mp;
int ans=0;
void dij(int x)
{
	memset(st,0,sizeof st);
	memset(dd,INF,sizeof dd);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,x});
	dd[x]=0;
	while(q.size()!=0)
	{
		auto t=q.top();
		q.pop();
		if(st[t.second]==1) continue;
		st[t.second]=1;
		for(auto i : v[t.second])
		{
			if(dd[i.node]>dd[t.second]+i.w)
			{
				dd[i.node]=dd[t.second]+i.w;
				q.push({dd[i.w],i.node});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int now,num;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			mp[a]++;
			q[a]=i;
			if(i==1 && j==1)
			{
				v[0].push_back({a,t,i});
				v[a].push_back({0,t,i});
				now=a;
				continue;
			}
			if(mp[a]>1)
			{
				num=t;
				now=a;
				continue;
			}
			v[now].push_back({a,t+num,i});
			v[a].push_back({now,t+num,i});
			now=0;
			now=a;
		}
	}
	while(p--)
	{
		cin>>x>>y;
		dij(x);
		cout<<dd[y]+dd[0]+w[x]+w[y]<<endl;
	}
	
	return 0;
} 
