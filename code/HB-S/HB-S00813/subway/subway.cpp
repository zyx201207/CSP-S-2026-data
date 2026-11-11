#include<bits/stdc++.h>
using namespace std;
long long c , n , m , d , q , sum , sx , sy , minn;
long long w[500005];
long long t[500005];
struct node
{
	long long num ;
	bool to;
};
node a[500005][500005];
vector<long long>sm[500005];
void dfs(long long x , long long num)
{
	if(x == sy)
		return;
	for(int i = 1 ; i <= m ; i ++)
	{
		int nx = a[x][i].to;
		if(nx == 1)
		{
			int f = 0;
			for(int j = 1 ; j <= n ; j ++)
			{
				flag = 0;
				for(int k = 1 ; k <= sm[n].size() ; k++)
				{
					if(sm[k] == x)
					{
						flag ++;
					}
					if(flag == nx)
						flag ++;
				}
				if(flag == 2) f = 1;
			}
			if(f != 1) num += t[i] ; 
			dfs(nx , num);
		}
		 
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> w[i];//kou -> ting
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		long long k;
		cin >> k;
		for(int j = 1 ; j <= k ; j ++)
		{
			long long zhan;
			cin >> zhan;
			sm[i].push_back(zhan);
			a[i][zhan] = {j,1};
			a[zhan][i] = {j,1};
			cin >> t[zhan]; // ting -> tai
		}
	}
	for(int i = 1 ; i <= q ; i ++)
	{
		cin >> sx >> sy;
		sum = w[sx] + t[sx];
		dfs(sx , sum);
		minn = min(minn , sum);
	}
	cout << minn;
	return 0;
}
