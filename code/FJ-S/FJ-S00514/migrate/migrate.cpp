#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
int c , t , n;
long long d , x[N] , num[N] , ans;
void dfs(int l , int r , int len)
{
	if(x[l] + d >= x[r])
	{
		len++;
		num[len]++;
		len--;
		return;
	}
	for(int i = r;i >= l + 1;i--)
	{
		if(x[l] + d >= x[i])
		{
			len++;
			dfs(i , r , len);
			len--;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				memset(num , 0 , sizeof(num));
				dfs(i , j , 0);
				for(int i = 1;i < N;i++)
				{
					if(num[i] == 2)
					{
						ans++;
					}
					else if(num[i])
					{
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}