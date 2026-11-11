#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long ktz[500005],zts[500005];
long long lns[505];
vector<long long>ltz[505];
long long st,ed,sra,srb,npos,nti,ntgli,njp,ans;
bool vis[500005];
/*
n 线路数
m 地铁站数
q 出行计划数
-st ed 起点、终点
kzt 地铁口到站厅时间 
 
zts 站台数量 
ztl 站厅到站台
-ln 站台线路
-ti 时间 

lns 线路长度 
ltz 线路途径地铁站 

going 乘车中状态 
-pos 所在地铁站 
-ti 已花时间 

npos 现在所在地铁站 
nti 现在已花时间
ntgli 现在乘坐的线路 
njp 现在将要到达的地铁站 

vis 某站是否到过 
ans 计划的最短时间 
*/
struct sta
{
	long long ln,ti;
};
vector<sta>ztl[500005];
struct going
{
	long long pos,ti;
};
queue<going>bq;
void init()
{
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>ktz[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>lns[i];
		for(long long j=1;j<=lns[i];j++)
		{
			cin>>sra>>srb;
			ztl[sra].push_back({i,srb});
			ltz[i].push_back(sra);
			zts[sra]++;
		}
	}
}
void bfs()
{
	while(!bq.empty()) bq.pop();
	bq.push({st,0});
	while(!bq.empty())
	{
		npos=bq.front().pos,nti=bq.front().ti;
		vis[npos]=1,bq.pop();
		for(long long i=0;i<zts[npos];i++)
		{
			ntgli=ztl[npos][i].ln;
			for(long long j=0;j<lns[ntgli];j++)
			{
				njp=ltz[ntgli][j];
				if(!vis[njp])
				{
					for(long long k=0;k<zts[njp];k++)
					{
						if(ztl[njp][k].ln==ntgli)
						{
//							cout<<npos<<"->"<<njp<<" by "<<ntgli<<": "<<ztl[npos][i].ti<<"+"<<ztl[njp][k].ti<<"\n";
							if(njp==ed) ans=min(ans,nti+ztl[npos][i].ti+ztl[njp][k].ti);
							bq.push({njp,nti+ztl[npos][i].ti+ztl[njp][k].ti});
							break;
						}
					}
				}
			}
		}
	}
}
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	while(q--)
	{
		ans=1145141919810;
		memset(vis,0,sizeof vis);
		cin>>st>>ed;
		bfs();
		cout<<ans+ktz[st]+ktz[ed]<<"\n";
	}
	return 0;
}
