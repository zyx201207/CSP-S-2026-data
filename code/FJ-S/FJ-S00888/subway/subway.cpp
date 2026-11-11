#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define int long long
using namespace std;
typedef pair<int,int> PII;//1 quanzhi  2 bianhao
int ww[500861];
int k[500861];
vector<int>a[586];
vector<int>t[586];//记得别+1！！！ 
vector<PII>dd[500861];//连向站台 
vector<PII>d1[586];//连向站厅 
vector<int>kk[500861];//第i个站厅分身 
int dist[1008611];
priority_queue<PII,vector<PII>,greater<PII>>hp;//1 quanzhi  2 bianhao
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x*=10,x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int dgf,n,m,d,q,qw,wq,tot=0,v,w,ans=1e18,qx,qy;
	cin>>dgf,n=read(),m=read(),d=read(),q=read();
	for(int u=1;u<=m;u++)
	ww[u]=read();
	for(int u=1;u<=n;u++)
	{
		k[u]=read();
		for(int p=1;p<=k[u];p++)
		{
			qw=read(),wq=read(),a[u].push_back(qw),t[u].push_back(wq);
			tot++,kk[qw].push_back(tot);
			dd[tot].push_back({wq,u}),d1[u].push_back({wq,tot});//第tot个分身连向站台u 
		}
	}
	while(q--)
	{
		qx=read(),qy=read(),ans=1e18;
		memset(dist,0x3f,sizeof(dist));
		for(auto &edge:kk[qx])
		{
			hp.push({0,edge});
			dist[edge]=0;
		}
		while(!hp.empty())
		{
			auto t=hp.top();
			hp.pop();
			v=t.second,w=t.first;
			if(w>dist[v])
			continue;
			if(v>tot)
			{
				v-=tot;
				for(auto &edge:d1[v])
				{
					if(dist[edge.second]>w+edge.first)
					dist[edge.second]=w+edge.first,hp.push({dist[edge.second],edge.second});
				}
			}
			else if(v<=tot)
			{
				for(auto &edge:dd[v])
				{
					if(dist[edge.second+tot]>w+edge.first)
					dist[edge.second+tot]=w+edge.first,hp.push({dist[edge.second+tot],edge.second+tot});
				}
			}
		}
		for(auto &edge1:kk[qy])
		ans=min(ans,dist[edge1]);
		cout<<ww[qx]+ans+ww[qy]<<endl;
	}
	return 0;
}
