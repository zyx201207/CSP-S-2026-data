#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10000];
int an,ans,k,maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(m == 1)
	{
		for(int i = 1;i <= n;i++)
		{
			cin >> ans;
			if(ans > an)
			{
				an = ans;
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n)
	{
		cin >> k;
		for(int i = 1;i <= n;i++)
		{
			cin >> ans;
			ans = ans & k;
			
		}
		cout << ans;
		return 0;
	}
	if(m == n-1)
	{
	
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i];
			}
			for(int i = 1;i <= 1000000;i++)
			{
					for(int i = 2;i <=m;i++)
				{
					ans = a[i -1] & a[i];
				}
				if(maxn < ans)
				{
					maxn = ans;
				}
				next_permutation(a ,a + n);
			}
		
		
		cout << ans;
		return 0;
		
	}
	return 0;
}
