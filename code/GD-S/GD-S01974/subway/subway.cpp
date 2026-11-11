#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500004];
struct node
{
	long long nxt,pre,val;
}e[50004];
long long h[50004];
int iscon[50004];
long long dist[50004];
vector<pair<long long,long long>>dis[50004];
long long v[50004];
long long k[30004];
vector<long long>a[505];
vector<long long>t[505];
long long cnt;
long long newnode;
void add(long long x,long long y,long long z)
{
	cnt++;
	e[cnt]={h[x],y,z};
	h[x]=cnt;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	newnode=m+m;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			long long t1,t2;
			cin>>t1>>t2;
			a[i].push_back(t1);
			t[i].push_back(t2);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(iscon[a[i][0]]==1)
		{
			newnode++;
			long long temp=a[i][0];
			a[i][0]=newnode;
			add(temp+m,a[i][0],t[i][0]);
			add(a[i][0],temp+m,t[i][0]);
		}
		else
		{
			add(a[i][0]+m,a[i][0],t[i][0]);
			add(a[i][0],a[i][0]+m,t[i][0]);
		}
		for(int j=1;j<k[i];j++)
		{
			if(iscon[a[i][j]]==1)
			{
				newnode++;
				a[i][j]=newnode;
				add(a[i][j],a[i][j-1],0);
				add(a[i][j-1],a[i][j],0);
			}
			else
			{
				iscon[a[i][j]]=1;
				iscon[a[i][j-1]]=1;
				add(a[i][j],a[i][j-1],0);
				add(a[i][j-1],a[i][j],0);
				add(a[i][j]+m,a[i][j],t[i][j]);
				add(a[i][j],a[i][j]+m,t[i][j]); 
			}
		}
	}
	for(int i=1+m;i<=m+m;i++)
	{
		priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>qu;
		memset(dist,0x3f,sizeof dist);
		memset(v,0,sizeof v);
		dist[i]=0;
		qu.push({0,i});//¾àÀë  ½Úµã
		for(long long j=1;j<=m+m+newnode;j++)
		{
			long long yy=qu.top().second;
			qu.pop();
			for(int k=h[yy];k;k=e[k].nxt)
			{
				long long nod=e[k].pre;
				if(dist[yy]+e[k].val<dist[nod])
				{
					dist[nod]=dist[yy]+e[k].val;
					qu.push({dist[nod],nod});
				}
			}
		}
		for(int j=1+m;j<=m+m;j++)
		{
			dis[i-m].push_back({j-m,dist[j]});
		}
	}
//	for(int i=1;i<=m+m+newnode;i++)
//	{
//		cout<<i<<":";
//		for(int j=h[i];j;j=e[j].nxt)
//		{
//			cout<<e[j].pre<<" "<<e[j].val<<" | ";
//		}
//		cout<<"\n";
//	}
	while(q--)
	{
		long long st,en;
		cin>>st>>en;
		if(st>en)swap(st,en);
		for(int i=0;i<dis[st].size();i++)
		{
			if(dis[st][i].first==en)
			{
				cout<<w[st]+w[en]+dis[st][i].second<<"\n";
				break;
			}
		}
		
	}
	return 0;
}
