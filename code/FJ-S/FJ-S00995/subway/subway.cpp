#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500+5;
const int MAXM=5e5+5;
const int MAXALL=2e7+5;//数据范围？？？3e8+5???

int c,n,m,d,q;
int nowsta[MAXM],tim[MAXM];
int dis[MAXM],flag[MAXM];
vector<pair<int,int>>v[MAXALL];
int cnt=1;
/*
n:地铁线路数（几号台）
m:地铁站数（几号口）
q:出行计划数	 
*/
int change(int flag,int i,int j)
{
	if(flag==1)
	{
		return i;
	}
	else if(flag==2)
	{
		return m+i;
	}
	else
	{
		return 2*m+n*(i-1)+j;
	}
}
void dijkstra(int st)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	dis[st]=0;
	q.push({0,st});
	while(q.size()>=1)
	{
		auto k=q.top();
		q.pop();
		if(flag[k.second]==1)
		{
			continue;
		}
		flag[k.second]=1;
		for(auto p:v[k.second])
		{
			if(dis[p.first]>dis[k.second]+p.second)
			{
				dis[p.first]=dis[k.second]+p.second;
				q.push({dis[p.first],p.first});
			}
		}
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
		v[change(1,i,0)].push_back({change(2,i,0),w});
		v[change(2,i,0)].push_back({change(1,i,0),w});
	}
	for(int i=1;i<=n;i++)
	{
		int sta;
		cin>>sta;
		for(int j=1;j<=m;j++)
		{
			nowsta[j]=0;
			tim[j]=0;
		}
		for(int num=1;num<=sta;num++)
		{
			cin>>nowsta[num]>>tim[num];
			v[change(2,nowsta[num],0)].push_back({change(3,nowsta[num],i),tim[num]});
			v[change(3,nowsta[num],i)].push_back({change(2,nowsta[num],0),tim[num]});
		}
		for(int num=2;num<=sta;num++)
		{
			v[change(3,nowsta[num-1],i)].push_back({change(3,nowsta[num],i),0});
			v[change(3,nowsta[num],i)].push_back({change(3,nowsta[num-1],i),0});
		}
	}
//	cnt--;
//	for(int i=1;i<=cnt;i++)
//	{
//		cout<<a[i].x<<' '<<a[i].y<<endl;
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=500000;i++)
		{
			dis[i]=LONG_LONG_MAX;
			flag[i]=0;
		}
		dijkstra(change(1,x,0));
		cout<<dis[change(1,y,0)]<<endl;
	}
	return 0;
} 
