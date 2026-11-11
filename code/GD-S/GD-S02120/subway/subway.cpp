#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
	int y,p;
	long long w;
	bool operator <(const node &a)const{
		return w > a.w;
	}
};
vector<int> g[500005],lx[500005];
int c,n,m,d,qq,l,r;
long long v[50005],k[505],a[505][50005],t[505][50005],ds[505][50005];
bool inl[505][50005];
void dij()
{
	priority_queue<node> q;
	memset(ds,0x3f,sizeof(ds));
	for(int i = 0;i < lx[l].size();i++)
	{
		int ll = lx[l][i];
		ds[ll][l] = v[l] + t[ll][l];
		q.push({l,ll,ds[ll][l]});
	}
	while(!q.empty())
	{
		int x = q.top().y,p = q.top().p,w = q.top().w;
		q.pop();
		for(int i = 0;i < g[x].size();i++)
		{
			int y = g[x][i];
			for(int j = 0;j < lx[y].size();j++)
			{
				int ll = lx[y][j];
				if(!inl[ll][x]) continue;
				if(ll == p)
				{
					if(ds[ll][y] > ds[ll][x])
					{
						ds[ll][y] = ds[ll][x];
						q.push({y,ll,ds[ll][y]});
					}
				}
				else
				{
					if(ds[ll][y] > ds[p][x] + t[p][x] + t[ll][y])
					{
						ds[ll][y] = ds[p][x] + t[p][x] + t[ll][y];
						q.push({y,ll,ds[ll][y]});
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qq;
	for(int i = 1;i <= m;i++) cin >> v[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			lx[a[i][j]].push_back(i);
			inl[i][a[i][j]] = 1;
			if(j > 1)
			{
				g[a[i][j - 1]].push_back(a[i][j]);
				g[a[i][j]].push_back(a[i][j - 1]);
			}
		}
	}
	while(qq--)
	{
		cin >> l >> r;
		dij();
		long long ans = 1e18;
		for(int i = 0;i < lx[r].size();i++)
		{
			int ll = lx[r][i];
			ans = min(ans,ds[ll][r] + t[ll][r] + v[r]);
		}
		cout << ans << endl;
	}
	return 0;
}
