#include<bits/stdc++.h>
using namespace std;
vector<int> g[30];
bool fw[30];
int n,k;
void dfs(int w,int now,int cl)
{
	fw[now]=cl;
	for(int q=0;q<g[now].size();q++)
	{
		if(!fw[g[now][q]]&&((w>>g[now][q]-1)&1))
		{
			dfs(w,g[now][q],cl);
		}
	}
}
bool ok(int q)
{
	memset(fw,0,sizeof fw);
	int sl=0;
	for(int w=0;w<n;w++)
	{
		if((q>>w)&1) sl++;
	}
	if(sl!=k) return 0;
	int cl=1;
	for(int w=0;w<n;w++)
	{
		if(((q>>w)&1)&&!fw[w+1]) dfs(q,w+1,cl++);
	}
	return cl<=3;
}
int main()
{
	//*
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//*/
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		for(int q=0;q<30;q++) g[q].clear();
		cin>>n>>k;
		for(int q=1;q<n;q++)
		{
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans=9999;
		for(int q=1;q<(1<<n);++q)
		{
			if(ok(q))
			{
				pair<int,int> dl[30];
				bool jd[30];
				memset(jd,0,sizeof jd);
				int dt=0,dw=1;
				for(int w=0;w<n;w++)
				{
					if((q>>w)&1) dl[++dt]={w+1,0},jd[w+1]=1;
				}
				int bans=0;
				while(dt>=dw)
				{
					auto now=dl[dw++];
					bans=max(bans,now.second);
					for(int w=0;w<g[now.first].size();w++)
					{
						if(!jd[g[now.first][w]])
						{
							dl[++dt]={g[now.first][w],now.second+1};
							jd[g[now.first][w]]=1;
						}
					}
				}
				ans=min(ans,bans);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
freeopen("hub.in","r",stdin);
freeopen("hub.out","w",stdout);
freeopen("hub.in","r",stdin);
freeopen("hub.out","w",stdout);
freeopen("hub.in","r",stdin);
freeopen("hub.out","w",stdout);
freeopen("hub.in","r",stdin);
freeopen("hub.out","w",stdout);
freeopen("hub.in","r",stdin);
freeopen("hub.out","w",stdout);
me want up mi huo xing wei da shang
so i love CCF
wow i love CCF
i wu yi am happy
but my fenshu is not gao
me wu yi shi fen nu de
beacouse i'm not hui xie

and me am the CQ-J00278
*/
