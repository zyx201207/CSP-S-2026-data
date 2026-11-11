#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,d;
	bool operator < (const node &a)const
	{
		return d>a.d;
	}
};
int c,n,m,d,p;
int dd[20005];
int a[20005];
int t[20005];
int arr[2000006];
int wei[2000006];
int nxt[2000006];
int hxd[2000006];
int dis[20005];
int tot=0;
priority_queue<node> q;
void add(int a,int b,int c)
{
	tot++;
	arr[tot]=b;
	wei[tot]=c;
	nxt[tot]=hxd[a];
	hxd[a]=tot;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>dd[i];
	}
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i]>>t[i];
			for(int j=1;j<i;j++)
			{
				add(a[i],a[j],t[i]+t[j]);
				add(a[j],a[i],t[i]+t[j]);
			}
		}
	}
	for(int i=1,x,y;i<=p;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=m;j++)
		{
			dis[j]=2e9;
			if(!q.empty())q.pop();
		}
		int k=x;
		dis[k]=0;
		q.push({x,0});
		while(!q.empty())
		{
			if(dis[q.top().id]!=q.top().d){q.pop();continue;}
			k=q.top().id;
			q.pop();
			if(k==y)
			{
				cout<<dd[x]+dd[y]+dis[y]<<endl;
				break;
			}
			for(int i=hxd[k],toto;i;i=nxt[i])
			{
				toto=arr[i];
				if(dis[toto]>dis[k]+wei[i])
				{
					dis[toto]=dis[k]+wei[i];
					q.push({toto,dis[toto]});
				}
			}
		}
	}
	return 0;
}
