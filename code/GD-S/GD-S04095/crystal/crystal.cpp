#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int n,ans;
long long m;
long long a[MAXN] , b[MAXN] , c[MAXN];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];

	sort(a + 1 , a + n + 1);//从小到大排序
	
	for(int i = 1 ; i <= n ; i++)
		b[i] = a[i + 1] - a[i];//我现在跳到下一个需要多少步数 
		
	for(int i = 1 ; i < n ; i++)
	{
		long long k = 0;
		int x = 1;
		for(int j = i ; j < n ; j++)
		{
			if(k + b[j] * x <= m)
			{
				k += b[j] * x;
				x++;
			}
			else
			{
				ans = max(ans,x);
				break;
			}
		}
	}
	
	cout << ans;
	
	return 0;
} 
