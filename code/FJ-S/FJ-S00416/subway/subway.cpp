//T2
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define debug cout<<"meow\n"; 
#define mkp make_pair	
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;
const int N=500;
const int M=5e5;
const int inf=2e18;
/*
对于任意两个点，步行如果只看步行时间可以将其转化为线路
只有500条线路，将每个线路到另一个线路的最小步行时间预处理（建图） n*m/d^2*m 根据数据范围选择方法，加上性质B有92
思考具体建图，模拟样例，看看正确性 （结尾） 
变成一个floyd，d不大，做完floyd直接暴力枚举由哪两个线路走到对方即可 
*/
int gunmu,n,m,d,q;
int k[N+5];
int w[M+5];
struct station{int a,t;};
vector<station>line[N+5];
vector<pair<int,int>>inlines[M+5];  int dd[M+5];
int book[M+5];
int dis[N+5][N+5];
void init_dis()
{
	rep(i,1,n) rep(j,1,n) dis[i][j]=inf;
	rep(i,1,n) dis[i][i]=0;
	return ;
}
signed main()
{
	cin.tie(0)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>gunmu>>n>>m>>d>>q;
	d=0;
	rep(i,1,m) cin>>w[i];
//	debug
	init_dis();
	rep(i,1,n)
	{
		cin>>k[i];
		rep(j,1,k[i])
		{
			int aa,tt;
			cin>>aa>>tt;
			inlines[aa].pb(mkp(i,tt));
			line[i].pb({aa,tt});	
			dd[aa]++;
			d=max(d,dd[aa]);
		}
	}
//	debug
	if(d*d<=n)
	{
		rep(stat,1,m)
		{
			for(auto line1:inlines[stat])
				for(auto line2:inlines[stat])
				{
					int i=line1.first,j=line2.first;
					if(i==j) continue;
//					cout<<i<<" "<<j<<":"<<line1.second<<" "<<line2.second<<"\n";
					dis[i][j]=dis[j][i]=min(dis[i][j],line1.second+line2.second);
//					cout<<"sdlfsdjllsdljdfj\n";
				}
		}
	}
	else
	{
		rep(i,1,n)
		{
			for(auto it:line[i])
			{
				int now=it.a,w=it.t;
				book[now]=w;
			}
			rep(j,1,n)
			{
				if(i==j) continue;
				for(auto it:line[j])
				{
					int now=it.a,w=it.t;
					if(book[now]) dis[i][j]=dis[j][i]=min(dis[i][j],book[now]+w);
				}
			}
			for(auto it:line[i])
			{
				int now=it.a,w=it.t;
				book[now]=0;
			}
		}	
	}
//	rep(i,1,n) 
//	{
//		rep(j,1,n) cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(k==i || k==j || i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	while(q--)
	{
		int ans=inf;
		int x,y;
		cin>>x>>y;
		for(auto line1:inlines[x]) for(auto line2:inlines[y]) 
			ans=min(ans,
			       dis[line1.first][line2.first]+
				   w[x]+w[y]
				   +line1.second+line2.second);
		cout<<ans<<"\n";
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
思路没问题，直接写 

0 5 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
0
0
1 6
2 3

*/
 
