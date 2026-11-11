#include<bits/stdc++.h>
using namespace std;
const int N = 3e2+5;
int c,t,n,d,x[N];
bool mp[N][N];
bool check(int x,int y)
{
	int cnt = 0;
	for(int i = x + 1;i < y;i++)
	{
		if(mp[x][i] && mp[i][y])cnt++;
	}
	return cnt == 2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(abs(x[i] - x[j]) <= d)mp[i][j] = 1;
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(check(i,j))ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*写不出来了喵 我还是太区了喵 只能追忆过去了喵 希望能在luogu上看到自己喵*/
