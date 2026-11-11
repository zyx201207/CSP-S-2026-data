//exp:60pts
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=2e4+5,N=505;
int c,n,m,d,tpp,w[M],a[N][M],t[N][M],k[N];
ll dis1[1004][1004],dis2[M];
bool vis1[1004],vis2[M];
struct road{
	ll t,val;
};
vector<road>l[M];
struct node{
	ll t,val;
	bool operator<(const node& a)const {return val>a.val;}
};
priority_queue<node> q; 
void dj(int st,int typ,int ed)
{
	while(!q.empty())q.pop(); 
	if(typ==1)
	{
		memset(vis1,0,sizeof(vis1));
		dis1[st][st]=0;
		q.push({st,0});
		while(!q.empty())
		{
			node nw=q.top();
			q.pop();
			if(vis1[nw.t])continue;
			vis1[nw.t]=1;
			for(road i:l[nw.t])
			{
				if(dis1[st][i.t]>dis1[st][nw.t]+i.val)
				{
					dis1[st][i.t]=dis1[st][nw.t]+i.val;
					q.push({i.t,dis1[st][i.t]});
				}
			}
		}
	}
	else{
		memset(vis2,0,sizeof(vis2));
		memset(dis2,0x3f,sizeof(dis2));
		dis2[st]=0;
		q.push({st,0});
		while(!q.empty())
		{
			node nw=q.top();
			q.pop();
			if(vis2[nw.t])continue;
			vis2[nw.t]=1;
			if(nw.t==ed)return;
			for(road i:l[nw.t])
			{
				if(dis2[i.t]>dis2[nw.t]+i.val)
				{
					dis2[i.t]=dis2[nw.t]+i.val;
					q.push({i.t,dis2[i.t]});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>tpp;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	//‘§¥¶¿Ì
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int h=j+1;h<=k[i];h++)
			{
				l[a[i][j]].push_back({a[i][h],t[i][j]+t[i][h]});
				l[a[i][h]].push_back({a[i][j],t[i][j]+t[i][h]});
			}
		}
	}
	if(m<=1000)
	{
		memset(dis1,0x3f,sizeof(dis1));
		for(int i=1;i<=m;i++)dj(i,1,0);
	}
	int x,y;
	while(tpp--)
	{
		cin>>x>>y;
		if(m<=1000) 
		{
			cout<<dis1[x][y]+w[x]+w[y]<<"\n";
		}
		else
		{
			dj(x,2,y);
			cout<<dis2[y]+w[x]+w[y]<<"\n";
		}
	}
	return 0;
}
