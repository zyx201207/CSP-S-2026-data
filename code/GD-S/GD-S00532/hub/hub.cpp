#include<bits/stdc++.h>

using namespace std;

namespace LHY
{

#define rep(i,s,t) for(long long i=(s);i<=(t);++i)
#define per(i,t,s) for(long long i=(t);i>=(s);--i)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mtp make_tuple
#define fi first
#define se second

bool Mst;

using LL=long long;
using LD=long double;
using ULL=unsigned long long;
using pii=pair<int,int>;
using tiii=tuple<int,int,int>;
using tiiii=tuple<int,int,int,int>;
using vi=vector<int>;

template<typename T> void _fpr(T v){cerr<<v<<'\n';}
template<typename T,typename... Args> void _fpr(T v,Args... args){cerr<<v<<' ';_fpr(args...);}
#define fpr(...) cerr<<"[on line "<<__LINE__<<"] ",_fpr(__VA_ARGS__)

int n,k; 

namespace Solve1
{
	const int N=4010;
	
	vi e[N];
	
	int cnt1[N][N];
	
	int cnt2[N][N];
	
	int dfs_dis(int cu,int pa,int d,int rt)
	{
		int maxd=d;
		for(int to:e[cu])
		{
			if(to==pa) continue;
			int P=dfs_dis(to,cu,d+1,rt);
			maxd=max(maxd,P);
		}
		++cnt1[rt][maxd-d];
		return maxd;
	}
	
	int dth[N],fa[N];
	
	int dfs1(int cu,int pa)
	{
		dth[cu]=dth[pa]+1;
		fa[cu]=pa;
		int maxn=dth[cu];
		for(int to:e[cu])
		{
			if(to==pa) continue;
			int P=dfs1(to,cu);
			maxn=max(maxn,P);
			rep(j,1,n)
			{
				cnt2[cu][j]+=cnt2[to][j];
			}
		}
		cnt2[cu][maxn-dth[cu]]+=1;
		return maxn;
	}
	
	const int inf_int=0x3f3f3f3f;
	
	int maxd[N],maxup[N*2][N],get_mid[N][N],othval[N][N];
	
	void dfs2(int cu,int pa,int d)
	{
		maxd[cu]=d;
		for(int to:e[cu])
		{
			if(to==pa) continue;
			dfs2(to,cu,d+1);
			maxd[cu]=max(maxd[cu],maxd[to]);
		}
	}
	
	void dfs3(int cu,int pa,int rt)
	{
//		fpr(cu);
		if(cu!=rt)
		{
			maxup[rt][cu]=max(maxup[rt][cu],maxup[rt][pa]);
		}
		pii fst=mp(-inf_int,0),snd=mp(-inf_int,0);
		for(int to:e[cu])
		{
			if(to==pa) continue;
			if(maxd[to]>=fst.fi)
			{
				snd=fst;
				fst=mp(maxd[to],to);
			}
			else if(maxd[to]>=snd.fi)
			{
				snd=mp(maxd[to],to);
			}
		}
		for(int to:e[cu])
		{
			if(to==pa) continue;
			if(to==fst.se)
			{
				maxup[rt][to]=max(maxup[rt][to],snd.fi);
			}
			else
			{
				maxup[rt][to]=max(maxup[rt][to],fst.fi);
			}
			dfs3(to,cu,rt);
		}
	}
	
	void dfs4(int cu,int pa,int rt,bool cg)
	{
		if(!cg)
		{
			maxup[rt][cu]=max(maxup[rt][cu],maxup[rt][pa]);
		}
		pii fst=mp(-inf_int,0),snd=mp(-inf_int,0);
		for(int to:e[cu])
		{
			if(to==pa) continue;
			if(maxd[to]>=fst.fi)
			{
				snd=fst;
				fst=mp(maxd[to],to);
			}
			else if(maxd[to]>=snd.fi)
			{
				snd=mp(maxd[to],to);
			}
		}
		for(int to:e[cu])
		{
			if(to==pa) continue;
			if(to==fst.se)
			{
				maxup[rt][to]=max(maxup[rt][to],snd.fi);
			}
			else
			{
				maxup[rt][to]=max(maxup[rt][to],fst.fi);
			}
			dfs4(to,cu,rt,0); 
		}
	}
	
	void get_vt(int cu,int pa,vi& vt)
	{
		vt.eb(cu);
		for(int to:e[cu])
		{
			if(to==pa) continue;
			get_vt(to,cu,vt);
		}
	}
	
	bool vis[N][N];
	
	int sum2[N];
	
	void solve()
	{
		rep(i,1,n-1)
		{
			int x,y;cin>>x>>y;
			e[x].eb(y),e[y].eb(x);
		}
		
		rep(i,1,n) rep(j,1,n) maxup[i][j]=0;
		rep(i,1,n) rep(j,1,n) cnt1[i][j]=0;
		rep(i,1,n) rep(j,1,n) cnt2[i][j]=0;
		rep(i,1,n) rep(j,1,n) othval[i][j]=0;
		rep(i,1,n) maxd[i]=0;
		rep(i,1,n) e[i].clear();
		
		rep(i,1,n)
		{
			dfs_dis(1,0,0,1); 
		} 
		dfs1(1,0);
		
		rep(rt,1,n)
		{
			dfs2(rt,0,0);
			dfs3(rt,0,rt);
			vector<vi> pvt;
			for(int to:e[rt])
			{
				vi vt;
				get_vt(to,rt,vt);
				pvt.eb(vt);
			}
			pii fst=mp(-inf_int,0),snd=mp(-inf_int,0),thd=mp(-inf_int,0);
			for(int to:e[rt])
			{
				if(maxd[to]>=fst.fi)
				{
					thd=snd;
					snd=fst;
					fst=mp(maxd[to],to);
				}
				else if(maxd[to]>=snd.fi)
				{
					thd=snd;
					snd=mp(maxd[to],to);
				}
				else if(maxd[to]>=thd.fi)
				{
					thd=mp(maxd[to],to);
				}
			}
			for(int p1=0;p1<pvt.size();++p1)
			{
				int nowothval=-inf_int;
				for(int p2=p1+1;p2<pvt.size();++p2)
				{
					if(pvt[p1][0]==fst.se||pvt[p2][0]==fst.se)
					{
						if(pvt[p1][0]==snd.se||pvt[p2][0]==snd.se)
						{
							nowothval=thd.fi;
						}
						else 
						{
							nowothval=snd.fi;
						}
					}
					else
					{
						nowothval=fst.fi;
					}
					for(int o1:pvt[p1]) for(int o2:pvt[p2])
					{
						get_mid[o1][o2]=rt;
						get_mid[o2][o1]=rt;
						othval[o1][o2]=nowothval;
						othval[o2][o1]=nowothval;
					}
				}
			}
		}
		
		int ppid=n;
		rep(q1,1,n) for(int q2:e[q1]) if(q1<q2)
		{
			++ppid;
			dfs4(q2,q1,ppid,1);
			dfs4(q1,q2,ppid,1);
			vi vt1,vt2;
			get_vt(q1,q2,vt1);
			get_vt(q2,q1,vt2);
			for(int o1:vt1) for(int o2:vt2)
			{
				get_mid[o1][o2]=ppid;
				get_mid[o2][o1]=ppid;
			}
		}
		
		int L=0,R=n,mid;
		while(L<=R)
		{
			mid=(L+R)/2;
			rep(i,1,n) sum2[i]=0;
			rep(i,1,n) rep(j,1,n) vis[i][j]=0;
			rep(i,1,n)
			{
				rep(j,mid+1,n)
				{
					sum2[i]+=cnt2[i][j];
				}
			}
			int minn=inf_int;
			rep(rt,1,n)
			{
				for(int p1:e[rt]) 
				{
					int sum1=0;
					rep(j,mid+1,n)
					{
						sum1+=cnt1[rt][j]-cnt2[p1][j];
					}
					vi vt;
					get_vt(p1,rt,vt);
					for(int to:vt)
					{
						vis[rt][to]=1;
						vis[to][rt]=1;
						int point_mid=get_mid[rt][to];
						minn=min(minn,max({sum1,sum2[to],othval[rt][to],maxup[point_mid][rt],maxup[point_mid][to]}));
					}
				}
			}
			rep(i,1,n) rep(j,i+1,n) if(!vis[i][j])
			{
				int point_mid=get_mid[i][j];
				minn=min(minn,max({sum2[i],sum2[j],maxup[point_mid][i],maxup[point_mid][j]}));
			}
			
			rep(i,1,n)
			{
				int nowcnt=0;
				rep(j,mid+1,n)
				{
					nowcnt+=cnt1[i][j];
				}
				minn=min(minn,nowcnt);
			}
			
			if(minn<=k)
			{
				R=mid-1;
			}
			else
			{
				L=mid+1;
			}
		}
		
		//remember to calc the single one
		
		cout<<L<<'\n';
	}
}

void solve()
{
	cin>>n>>k;
	if(n<=4000)
	{
		Solve1::solve();
	}
}

bool Med;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	
	int Tst=clock();
	
	int c,T;cin>>c>>T;while(T--) solve();
	
	int Ted=clock();
	
	cerr<<"T:"<<1.0*(Ted-Tst)/CLOCKS_PER_SEC<<'\n';
	cerr<<"M:"<<(&Mst-&Med)/1024.0/1024.0<<'\n';
	
	return 0;
}

}

int main()
{
	return LHY::main();
}
