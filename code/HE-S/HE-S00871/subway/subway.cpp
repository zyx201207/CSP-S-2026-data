#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5*5+10,M=1e2*5+10;
int c,n,m,d,q;
int w[N],k[M];
int a[M][M],t[M][M];
ll ans;
bool qd=0;
vector<pair<int ,int > >l[N];
void solve(int x,int y)
{
	for(int i=0;i<l[x].size();i++)
	{
		if(l[x][i].first==y)
		{
			ans+=l[x][i].second;
			qd=1;
			return;
		}
		else
		{
			ans+=l[x][i].second;
			solve(l[x][i].first,y);
			if(!qd)
			{
				ans-=l[x][i].second;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int o=j+1;o<=k[i];o++)
			{
				int x=a[i][j],y=a[i][o];
				l[x].push_back({y,t[i][j]+t[i][o]});
			}
		}
	}
	while(q--)
	{
		ans=0;
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		solve(x,y);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//n=2两条地铁线
//m=5五个站台
//q=2两次询问
//w={4,1,9,2,5}  地铁口->站厅
//a={1,2,4
//   2,3,5}每条地铁线通过的地铁口
//t={5,7,6
//   3,4,7} 站厅->到地铁线 
//x起点
//y终点 
//666不会了 

