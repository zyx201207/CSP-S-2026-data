#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
const int inf = 0x3f3f3f3f3f3f;
int c,n,m,d,q,ans;
int w[N];
struct tran
{
	int id,t;
};
vector<tran> vc[N];
int ma[600][600];
void init()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vc[i].size();j++)
		{
			for(int k=j+1;k<vc[i].size();k++)
			{
				ma[vc[i][j].id][vc[i][k].id] = min(ma[vc[i][j].id][vc[i][k].id],vc[i][j].t+vc[i][k].t);
				ma[vc[i][k].id][vc[i][j].id] = min(ma[vc[i][k].id][vc[i][j].id],vc[i][j].t+vc[i][k].t);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				ma[i][j] = min(ma[i][j],ma[i][k]+ma[j][k]);
			}
		} 
	}
	for(int i=1;i<=n;i++)
	{
		ma[i][i]=0;
	}
} 
int solve(int x,int y)
{
	int ans = inf;
	for(int i=0;i<vc[x].size();i++)
	{
		for(int j=0;j<vc[y].size();j++)
		{
			ans = min(ma[vc[x][i].id][vc[y][j].id]+w[x]+w[y]+vc[x][i].t+vc[y][j].t,ans);
		}
	}
	return ans;
}
//处理出每个地铁到另一条地铁的换乘时间即可 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ma,inf,sizeof(ma));
	//cout<<ma[1][1]<<endl;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) 
	{
		int k;
		int last = 0;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++) 
		{
			int v,t;
			scanf("%lld %lld",&v,&t);
			vc[v].push_back(tran{i,t});
			//ma[v][last] = ma[last][v] = 0;
			last = v;
		}
	}//建边 
	init();
	while(q--)
	{
		int x,y;
		scanf("%lld %lld",&x,&y);
		//cout<<"a"<<endl;
		cout<<solve(x,y)<<endl;
	}
}

