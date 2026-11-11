#include<bits/stdc++.h>
using namespace std;
const int MAXN=1200;
const int MAXM=5e5+500;
const int INF=0x7fffffff;
int C,n,m,d,q;
class subtask_pack
{
	public:
		
		int ans[MAXN][MAXN];
		int Node_Value[MAXN];
		struct data
		{
			int node,time;
		};
		vector<data> subway[MAXN];
		struct data_start
		{
			int subwayid,idx;
		};
		vector<data_start> st[MAXN];
		bitset<MAXN> use;
		bitset<MAXN> empty_example;
		void solve_ans(int subwayid,int idx,int iidx,int sum)
		{
			if (use[subwayid]) return;
			use[subwayid]=true;
			for (int i=idx;i<(int)subway[subwayid].size();i++)
			{
				int new_start=subway[subwayid][i].node;
				int new_sum=sum+subway[subwayid][i].time;
				if (i==idx) new_sum=sum;
				ans[iidx][new_start]=min(ans[iidx][new_start],new_sum);
				for (int j=0;j<(int)st[new_start].size();j++)
				{
					solve_ans(st[new_start][j].subwayid , st[new_start][j].idx , iidx , new_sum+subway[st[new_start][j].subwayid][st[new_start][j].idx].time);
				}
			}
			for (int i=idx-1;i>=0;i--)
			{
				int new_start=subway[subwayid][i].node;
				int new_sum=sum+subway[subwayid][i].time;
				ans[iidx][new_start]=min(ans[iidx][new_start],new_sum);
				for (int j=0;j<(int)st[new_start].size();j++)
				{
					solve_ans(st[new_start][j].subwayid , st[new_start][j].idx , iidx , new_sum+subway[st[new_start][j].subwayid][st[new_start][j].idx].time);
				}
			}
		}
		void solve(int idx)
		{
			for (int i=0;i<(int)st[idx].size();i++)
			{
				use=empty_example;
				solve_ans(st[idx][i].subwayid,st[idx][i].idx,idx,subway[st[idx][i].subwayid][st[idx][i].idx].time);
			}
			return;
		}
		void inputt()
		{
			for (int i=0;i<=1100;i++)
			{
				for (int j=0;j<=1100;j++)
				{
					ans[i][j]=INF;
				}
			}
			for (int i=1;i<=m;i++)
			{
				cin>>Node_Value[i];
			}
			data node_test;
			data_start node_st_test;
			for (int i=1,k;i<=n;i++)
			{
				cin>>k;
				for (int j=0,a,t;j<k;j++)
				{
					cin>>a>>t;
					node_st_test.subwayid=i;
					node_st_test.idx=j;
					st[a].emplace_back(node_st_test);
					node_test.node=a;
					node_test.time=t;
					subway[i].emplace_back(node_test);
				}
			}
			for (int i=1;i<=m;i++)
			{
				use=empty_example;
				solve(i);
			}
			for (int i=1;i<=m;i++)
			{
				for (int j=i+1;j<=m;j++)
				{
					ans[j][i]=ans[i][j]=ans[i][j]+Node_Value[i]+Node_Value[j];
				}
			}
			for (int i=1,x,y;i<=q;i++)
			{
				cin>>x>>y;
				cout<<ans[x][y]<<endl;
			}
		}
}Plan_After;
class subtask1
{
	public:
		int ans[MAXN][MAXN];
		int Node_Value[MAXN];
		struct data
		{
			int node,time;
		};
		vector<data> subway[MAXN];
		struct data_start
		{
			int subwayid,idx;
		};
		vector<data_start> st[MAXN];
		bitset<MAXN> use;
		bitset<MAXN> empty_example;
		void solve_ans(int subwayid,int idx,int iidx,int sum)
		{
			if (use[subwayid]) return;
			use[subwayid]=true;
			for (int i=idx;i<(int)subway[subwayid].size();i++)
			{
				int new_start=subway[subwayid][i].node;
				if (new_start<idx) continue;
				int new_sum=sum+subway[subwayid][i].time;
				if (i==idx) new_sum=sum;
				ans[iidx][new_start]=min(ans[iidx][new_start],new_sum);
				for (int j=0;j<(int)st[new_start].size();j++)
				{
					solve_ans(st[new_start][j].subwayid , st[new_start][j].idx , iidx , new_sum+subway[st[new_start][j].subwayid][st[new_start][j].idx].time);
				}
			}
			for (int i=idx-1;i>=0;i--)
			{
				int new_start=subway[subwayid][i].node;
				if (new_start<idx) continue;
				int new_sum=sum+subway[subwayid][i].time;
				ans[iidx][new_start]=min(ans[iidx][new_start],new_sum);
				for (int j=0;j<(int)st[new_start].size();j++)
				{
					solve_ans(st[new_start][j].subwayid , st[new_start][j].idx , iidx , new_sum+subway[st[new_start][j].subwayid][st[new_start][j].idx].time);
				}
			}
		}
		void solve(int idx)
		{
			for (int i=0;i<(int)st[idx].size();i++)
			{
				use=empty_example;
				solve_ans(st[idx][i].subwayid,st[idx][i].idx,idx,subway[st[idx][i].subwayid][st[idx][i].idx].time);
			}
			return;
		}
		void inputt()
		{
			for (int i=0;i<=1100;i++)
			{
				for (int j=0;j<=1100;j++)
				{
					ans[i][j]=INF;
				}
			}
			for (int i=1;i<=m;i++)
			{
				cin>>Node_Value[i];
			}
			data node_test;
			data_start node_st_test;
			for (int i=1,k;i<=n;i++)
			{
				cin>>k;
				for (int j=0,a,t;j<k;j++)
				{
					cin>>a>>t;
					node_st_test.subwayid=i;
					node_st_test.idx=j;
					st[a].emplace_back(node_st_test);
					node_test.node=a;
					node_test.time=t;
					subway[i].emplace_back(node_test);
				}
			}
			for (int i=1;i<=m;i++)
			{
				use=empty_example;
				solve(i);
			}
			for (int i=1;i<=m;i++)
			{
				for (int j=i+1;j<=m;j++)
				{
					ans[j][i]=ans[i][j]=ans[i][j]+Node_Value[i]+Node_Value[j];
				}
			}
			for (int i=1,x,y;i<=q;i++)
			{
				cin>>x>>y;
				cout<<ans[x][y]<<endl;
			}
		}
}Plan_A;
class subtask2
{
	public:
		map<int,int> ans[MAXM];
		int Node_Value[MAXM];
		struct data
		{
			int node,time;
		};
		vector<data> subway[MAXM];
		struct data_start
		{
			int subwayid,idx;
		};
		vector<data_start> st[MAXM];
		bitset<MAXM> use;
		bitset<MAXM> empty_example;
		void solve_ans(int subwayid,int idx,int iidx,int sum)
		{
			if (use[subwayid]) return;
			use[subwayid]=true;
			for (int i=idx;i<(int)subway[subwayid].size();i++)
			{
				int new_start=subway[subwayid][i].node;
				if (new_start<idx) continue;
				int new_sum=sum+subway[subwayid][i].time;
				if (i==idx) new_sum=sum;
				if (ans[iidx][new_start]==0) ans[iidx][new_start]=new_sum;
				else
				{
					ans[iidx][new_start]=min(ans[iidx][new_start],new_sum);
				}
				for (int j=0;j<(int)st[new_start].size();j++)
				{
					solve_ans(st[new_start][j].subwayid , st[new_start][j].idx , iidx , new_sum+subway[st[new_start][j].subwayid][st[new_start][j].idx].time);
				}
			}
			for (int i=idx-1;i>=0;i--)
			{
				int new_start=subway[subwayid][i].node;
				if (new_start<idx) continue;
				int new_sum=sum+subway[subwayid][i].time;
				if (ans[iidx][new_start]==0) ans[iidx][new_start]=new_sum;
				else ans[iidx][new_start]=min(ans[iidx][new_start],new_sum);
				for (int j=0;j<(int)st[new_start].size();j++)
				{
					solve_ans(st[new_start][j].subwayid , st[new_start][j].idx , iidx , new_sum+subway[st[new_start][j].subwayid][st[new_start][j].idx].time);
				}
			}
		}
		void solve(int idx)
		{
			for (int i=0;i<(int)st[idx].size();i++)
			{
//				cout<<i<<endl;
				use=empty_example;
				solve_ans(st[idx][i].subwayid,st[idx][i].idx,idx,subway[st[idx][i].subwayid][st[idx][i].idx].time);
			}
			return;
		}
		void inputt()
		{
			for (int i=1;i<=m;i++)
			{
				cin>>Node_Value[i];
			}
			data node_test;
			data_start node_st_test;
			for (int i=1,k;i<=n;i++)
			{
				cin>>k;
				for (int j=0,a,t;j<k;j++)
				{
					cin>>a>>t;
					node_st_test.subwayid=i;
					node_st_test.idx=j;
					st[a].emplace_back(node_st_test);
					node_test.node=a;
					node_test.time=t;
					subway[i].emplace_back(node_test);
				}
			}
			for (int i=1;i<=m;i++)
			{
				cout<<i<<endl;
				use=empty_example;
				solve(i);
			}
			for (int i=1;i<=m;i++)
			{
				for (int j=i+1;j<=m;j++)
				{
					ans[j][i]=ans[i][j]=ans[i][j]+Node_Value[i]+Node_Value[j];
				}
			}
			for (int i=1,x,y;i<=q;i++)
			{
				cin>>x>>y;
				cout<<ans[x][y]<<endl;
			}
		}
}Plan_B;

int main()
{
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	if (m<=1000)
	{
		Plan_A.inputt();
	}
	else
	{
		Plan_B.inputt();
	}
	return 0;
}
