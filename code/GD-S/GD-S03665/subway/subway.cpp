#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)
#define rd "%lld"
#define int long long

namespace marlin
{
	int c,n,m,d,q;
	constexpr int N=505;
	constexpr int M=5e5+5;
	struct stop
	{
		int lest,tout;
		stop(int lest_,int tout_)
		{
			lest=lest_;tout=tout_;
		}
	};
	struct node
	{
		int leng,next;
		node(int leng_,int next_)
		{
			leng=leng_;next=next_;
		}
	};
	vector<stop> stops[M];
	vector<node> map[N];
	vector<int> linestops[N];
	int getinout[M];
	bool everl[N], ever[N];
	int rs[N][N];
	int qs[N][N];
	void get_roads(int lest)
	{
		if (ever[lest]) return;
		ever[lest]=true;
		
		// initialize
		for (register int i=0;i<=m;i++)
		{
			everl[i]=false;
			qs[lest][i]=LLONG_MAX;
		}
		for (register int i=0;i<=n;i++)
		qs[lest][i]=LLONG_MAX;
		qs[lest][lest]=0;
		
		everl[lest]=true;
		queue<int> ue; ue.push(lest);
		while (ue.size())
		{
			int x=ue.front();ue.pop();
			for (const node& node : map[x])
			{
				int ndis=qs[lest][x]+node.leng;
				if (ndis<qs[lest][node.next])
				{
					qs[lest][node.next]=ndis;
					if (!everl[node.next])
					{
						ue.push(node.next);
						everl[node.next]=true;
					}
				}
			}
		}
	}
	void main()
	{
		scanf(rd rd rd rd rd,&c,&n,&m,&d,&q);
		getinout[0]=0;
		for (register int i=1;i<=m;i++)
		scanf(rd,getinout+i);
		for (register int i=1;i<=n;i++)
		{
			int k; scanf(rd,&k);
			for (register int j=0;j<k;j++)
			{
				int w,t; scanf(rd rd,&w,&t);
				stops[w].push_back(stop(i,t));
				linestops[i].push_back(w);
			}
		}
		
		for (register int i=0;i<=n;i++)
		ever[i]=false;
		
		for (register int i=0;i<=n;i++)
		for (register int j=0;j<=n;j++)
		{
			if(!i||!j||(i==j)) rs[i][j]=0;
			else rs[i][j]=LLONG_MAX;
		}
		
		for (register int i=1;i<=m;i++)
		{
			if (stops[i].size()==1) continue;
			for (register int j=0;j<stops[i].size();j++)
			{
				for (register int k=j+1;k<stops[i].size();k++)
				{
					rs[stops[i][k].lest][stops[i][j].lest]=
					rs[stops[i][j].lest][stops[i][k].lest]=
					min(rs[stops[i][j].lest][stops[i][k].lest],
					stops[i][j].tout+stops[i][k].tout);
				}
			}
		}
		
		for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
		{
			if (i==j) continue;
			if (rs[i][j]==LLONG_MAX) continue;
			//WHENDEBUG printf("push. i " rd " j " rd " rs " rd "\n",
			//	i,j,rs[i][j]);
			map[i].push_back(node(rs[i][j],j));
		}
		
		// mainly
		
		for (register int i=0;i<q;i++)
		{
			int wa,wb; scanf(rd rd,&wa,&wb);
			int ans=LLONG_MAX;
			WHENDEBUG printf("wa. " rd "\n", wa);
			for (const stop& s : stops[wa])
			{
				get_roads(s.lest);
				for (const stop& bs : stops[wb])
				{
					if (s.tout+bs.tout+qs[s.lest][bs.lest]<0ll) continue;
					ans=min(ans,s.tout+bs.tout+qs[s.lest][bs.lest]);
					WHENDEBUG printf("ansb. " rd " a " rd " b " rd "\n",
						ans,s.lest,bs.lest);
				}
				WHENDEBUG printf("ansA. " rd "\n", ans);
			}
			ans+=getinout[wa]+getinout[wb];
			printf(rd "\n",ans);
		}
	}
}

signed main()
{
	WHENDEBUG freopen("subway3.in","r",stdin);
	WHENDEBUG{}else freopen("subway.in","r",stdin);
	WHENDEBUG{}else freopen("subway.out","w",stdout);
	//freopen("subway5.in","r",stdin);
	//freopen("subway.out","w",stdout);
	marlin::main();
	return 0;
}
