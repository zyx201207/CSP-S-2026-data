#include<bits/stdc++.h>
using namespace std;
struct di
{
	int no,prex,ans;//prex=0走进站 
	friend bool operator<(di a,di b)
	{
		return a.ans>b.ans;
	} 
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	vector<int>W(m+1);
	vector<vector<long long>>A(n+1),T(m+1,vector<long long>(n+1)),lt(m+1,vector<long long>(n+1));
	//T[a][b]=在第a个站上,从第b条线走到站厅的时间 
	//lt[a][b]=在第a个站上,能靠线路b一步走到的站 
	for(int q=1;q<=m;q++)
	{
		cin>>W[q];
	}
	for(int q=0;q<=m;q++)
	{
		for(int w=0;w<=n;w++)
		{
			T[q][w]=lt[q][w]=INT_MAX;
		}
	}
	for(int q=1;q<=n;q++)
	{
		int gs;
		cin>>gs;
		A[q].push_back(0);
		T[q].push_back(0);
		for(int w=1;w<=gs;w++)
		{
			int z,x;
			cin>>z>>x;
			A[q].push_back(z);
			T[z][q]=x;
		}
	}
	for(int q=1;q<=n;q++)
	{
		for(int w=1;w<A[q].size()-1;w++)
		{
			lt[A[q][w]][q]=A[q][w+1];
			lt[A[q][w+1]][q]=A[q][w];
		}
	}
	for(int q=0;q<Q;q++)
	{
		int x,y;
		cin>>x>>y;
		priority_queue<di>dl;
		vector<int>dis(m+1,-1);
		dl.push(di{x,0,W[x]});
		dis[x]=W[x];
		while(!dl.empty())
		{
			di tmp=dl.top();
			dl.pop();
			for(int w=1;w<=n;w++)
			{
				if(lt[tmp.no][w]==INT_MAX)
				{
					continue;
				}
				di ne=tmp;
				//T[a][b]=在第a个站上,从第b条线<->站厅的时间 
				//lt[a][b]=在第a个站上,能靠线路b一步走到的站 
				ne.no=lt[tmp.no][w];
				//以下是换乘
				ne.ans+=T[ne.no][ne.prex]; 
				for(int e=1;e<=n;e++)
				{
					di nne=ne;
					if(T[ne.no][e]!=INT_MAX)
					{
						if(nne.prex!=e)
						{
							nne.ans+=T[ne.no][e];
							nne.prex=e;
						}
						if(nne.ans<dis[nne.no]||dis[nne.no]==-1)
						{
							dl.push(nne);
							dis[nne.no]=nne.ans;
						}
					}
				}
			}
		}
		cout<<dis[y]<<"\n";
	}
}
