#include<bits/stdc++.h>
#define Ibuki Suika
#define int long long
#define PII pair<int,int>
int const X=1e5+10;
using namespace std;
int h[X],e[X],ne[X],idx=0,w[X],d[X];
bool st[X]={0};
int c,n,m,dx,qq,rukou[X];
int df1[X],df2[X],df3[X];
int ti1[X],ti2[X],ti3[X];
priority_queue<PII,vector<PII >,greater<PII > > q;
int dij(int x)
{
	d[0]=0;
	q.push({0,0});
	while(q.size())
	{
		auto t=q.top();
		q.pop();
		int dist=t.first,ver=t.second;
		if(st[ver]) continue;
		st[ver]=1;
		for(int i=h[ver];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(d[j]>w[j]+dist)
			{
				d[j]=w[j]+dist;
			}
			q.push({d[j],j});
		}
	}
	return d[x];
}
void add(int a,int b,int c)
{
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	memset(d,0x3f,sizeof d);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&dx,&qq);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",rukou[i]);
	}
	
	return 0;
}