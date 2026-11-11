#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 500 + 5;
const int M = 5e5 + 10;
int c,n,m,d,q;
//n<=500,m<=k求和<=5e5
//d<=20,q<=1e5 
int w[M];//[1,1e9]
int k[N];//和<=5e5 
//vector<int> a[N];//<=m
//vector<int> t[N];//<=1e9
vector<pair<int,int> > to[M];
//to[i]:i号地铁站所在的地铁线路，总空间为k求和，<=5e5 
ll dis[N][N];
//(<=t+t)<=2e9,表示地铁线路的距离，空间O(n*n)=2.5e5 
void solve()
{
	//O(d*d*m)<=2e8
	//O(n*n*n)<=1.25e8
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dis[i][j] = 2e18 + 1;
		}
		dis[i][i] = 0;
	}
	for(int i = 1,l,j,k; i <= m; i++)
	{
		l = to[i].size();
		for(j = 0; j < l; j++)
		{
			for(k = j + 1; k < l; k++)
			{
				dis[to[i][j].first][to[i][k].first] = min(dis[to[i][j].first][to[i][k].first],
				(ll)to[i][j].second + to[i][k].second);
				dis[to[i][k].first][to[i][j].first] = 
				dis[to[i][j].first][to[i][k].first];
			}
		}
	}
	for(int k = 1,i,j; k <= n; k++)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	return;
}
int lx,ly;ll ans;
ll getdis(int x,int y)//O(d*d)<=4e2
{
	lx = to[x].size();
	ly = to[y].size();
	ans = to[x][0].second + dis[to[x][0].first][to[y][0].first] + to[y][0].second;
	for(int ii = 0,i,jj,j; ii < lx; ii++)
	{
		i = to[x][ii].first;
		for(jj = 0; jj < ly; jj++)
		{
			j = to[y][jj].first;
			ans = min(ans,
			to[x][ii].second + dis[i][j] + to[y][jj].second);
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;c = 0;
	cin>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++)
	{
		cin>>w[i];
	}
	for(int i = 1,j,a,t; i <= n; i++)
	{
		cin>>k[i];
		for(j = 0; j < k[i]; j++)
		{
//			cin>>a[i][j]>>t[i][j];
//			to[a[i][j]].push_back(make_pair(i,t[i][j]));
			cin>>a>>t;
			to[a].push_back(make_pair(i,t));
		}
	}
	solve();
	int x,y;ll ans;
	while(q--)//q<=1e5,O(d*d*q)<=4e7
	{
		cin>>x>>y;//x != y,1<=x,y<=m
		cout<<(getdis(x,y) + w[x] + w[y])<<endl;
	}
	return 0;
}

