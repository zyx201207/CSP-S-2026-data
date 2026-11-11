#include<bits/stdc++.h>
using namespace std;
long long c1,m,n,d,q3,c[25],dis[505];
struct node1{
	long long s1,w1;
};
node1 q4;
struct zt{
	long long w;
	vector<node1> link;
};
zt a[505];//站台 
struct sub{
	long long t,wz;
};
sub b[25][500005];//地铁 
struct node{
	long long di,zt,sub,w2;
	bool operator<(const node& x) const
	{
		return di>x.di;
	} 
};
node q1,q2;
priority_queue<node> q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q3;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].w;
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=c[i];j++)
		{
			cin>>b[i][j].wz>>b[i][j].t;
			q4.s1=i;
			q4.w1=b[i][j].wz;
			a[b[i][j].wz].link.push_back(q4);
		}
	}
	while(q3>0)
	{
		fill(dis+1,dis+1+n,0x3f3f3f3f);
		q3--;
		int x,y;
		cin>>x>>y;
		q1.zt=x;
		for(int i=0;i<a[x].link.size();i++)
		{
			q1.sub=a[x].link[i].s1;
			q1.di=a[x].w+b[a[x].link[i].s1][a[x].link[i].w1].t;
			q1.w2=a[x].link[i].w1;
			q.push(q1);
		}
		while(!q.empty())
		{
			q1=q.top();
			q.pop();
			if(q1.di>dis[q1.zt])
			{
				continue;
			}
			if(q1.zt==y)
			{
				cout<<q1.di+a[y].w<<endl;
				break;
			}
			q2.di=q1.di+b[q1.sub][q1.w2+1].t;//坐下一站 
			q2.sub=q1.sub;
			q2.w2=q1.w2+1;
			q2.zt=b[q1.sub][q1.w2+1].wz;
			q.push(q2);
			for(int i=0;i<a[q1.sub].link.size();i++)
			{
				q2.di=q1.di+b[a[q1.sub].link[i].s1][q1.w2+1].t+b[b[a[q1.sub].link[i].s1][q1.w2+1].wz][q1.w2+1].t;
				q2.sub=a[q1.sub].link[i].s1;
				q2.w2=q1.w2;
				q2.zt=b[a[q1.sub].link[i].s1][q1.w2+1].wz;
				if(q2.di<dis[q2.zt])
				{
					dis[q2.zt]=q2.di;
					q.push(q2);
				}
			}
		}
	}
	return 0;
}
