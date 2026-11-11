#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int a[N],r[N],dd[N],len,v[N],last[N];
int c,t,n,d;
struct edge
{
	int x,y,nxt; 
}e[N];
void add(int x,int y)
{
	e[++len].x=x,e[len].y=y,e[len].nxt=last[x];
	last[x]=len;
} 
int dij(int x)
{
	memset(dd,63,sizeof(dd));
	memset(v,0,sizeof(v));
	memset(r,0,sizeof(r));
	dd[x]=0,v[x]=1;
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		int s=q.top().second;
		q.pop();
		v[s]=0;
		for(int i=s;i;i=e[i].nxt)
		{
			int y=e[i].y;
			if(dd[y]==dd[s]+1)
			{
				r[y]++;
			}
			if(dd[y]>dd[s]+1)
			{
				dd[y]=dd[s]+1;
				r[y]=1;
				if(!v[y])
				{
					v[y]=1;
					q.push(make_pair(-dd[y],y));
				}
			}
		}
	}
	int tot=0;
	for(int i=x+1;i<=n;i++) if(r[i]==2) tot++;
	return tot;
}
int main()
{
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			int j=i+1;
			while(a[j]-a[i]<=d)
			{
				add(i,j);
				j++; 
			} 
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=dij(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
