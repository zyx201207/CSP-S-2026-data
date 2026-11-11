#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
struct Sta{
	int w;
	vector<pair<int,int> > xian;//fi xian,se time
};
Sta sta[500005];
vector<int> Xian[505];
int en;int mit=1e9;
bool vis[500005];
void dfs(int no_st,int no_xi,int tim)
{
	//cout<<no_st<<" "<<no_xi<<" "<<tim<<'\n';
	if(tim>mit) return;
	if(no_st==en)
	{
		for(int i=0;i<sta[no_st].xian.size();i++)
		{
			if(sta[no_st].xian[i].fi==no_xi) {tim+=sta[no_st].xian[i].se;break;}
		}
		mit=min(mit,tim);
		//-----------------------------------------------------------
		//cout<<'\n';
		
		return;
	}
	for(int i=0;i<sta[no_st].xian.size();i++)
	{
		int to_xi=sta[no_st].xian[i].fi,to_t=sta[no_st].xian[i].se;
		for(int j=0;j<Xian[to_xi].size();j++)
		{
			if(vis[Xian[to_xi][j]]) continue;
			vis[Xian[to_xi][j]]=1;
			if(to_xi!=no_xi)
			{
				for(int k=0;k<sta[no_st].xian.size();k++)
				{
					if(sta[no_st].xian[k].fi==no_xi) {to_t+=sta[no_st].xian[k].se;break;}
				}
			}
			if(to_xi==no_xi) dfs(Xian[to_xi][j],to_xi,tim);
			else dfs(Xian[to_xi][j],to_xi,tim+to_t);
			//----------------------------------------------------------------------
			//cout<<"\n";
			vis[Xian[to_xi][j]]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>sta[i].w;
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			sta[a].xian.push_back({i,t});
			Xian[i].push_back(a);
		}
	}
	while(q--)
	{
		int st;
		cin>>st>>en;
		vis[st]=1;
		for(int i=0;i<sta[st].xian.size();i++) dfs(st,sta[st].xian[i].fi,sta[st].w+sta[st].xian[i].se);
		cout<<mit+sta[en].w<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
