#include<iostream>
using namespace std;

int c, t, n, d, x[5005], u, v, minn = 0x3f3f3f3f, ans = 0; 

void dfs(int now, int total)
{
	if(now == v) 
	{
		if(total == minn) ans ++;
		else{
			minn = min(minn, total);
			ans = 0;
		}
		return ;
	}
	for(int i = now + 1; i <= n; i++)
	{
		if(abs(x[i] - x[now]) <= d && total <=  minn)
		{
			dfs(i, total + abs(x[i] - x[now]));
		}
	}	
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin >> c >> t;
	
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		 } 
		 int total = 0;
		for(int u = 1; u < n; u++)
		{
			for(v = u + 1; v <= n; v++)
			{
				dfs(u, 0);
				if(ans == 2)
				{
					total ++ ;
				}
				ans = 0;
				minn = 0x3f3f3f3f;
			}
		}
		cout << total << endl;
	}
	return 0;
 } 
