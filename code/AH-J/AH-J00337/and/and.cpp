# include <bits/stdc++.h>
# define int long long
using namespace std;

const int N = 2e5+5;
int n,m,a[N],k,f[N];
vector<int> v[32];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
		f[i] = 1;
		for (int j = 30; j >= 0; j--)
		{
			if (a[i] >= (1<<j)) v[j].push_back(i),a[i] -= (1<<j);
		}
	}	
	for (int i = 30; i >= 0; i--)
	{
		int t = 0,l = v[i].size();
		for (int j = 0; j < l; j++) 
			if (f[v[i][j]]) t++,f[v[i][j]] = 2;
		if (t >= m)
		{
			for (int j = 1; j <= n; j++)
				if (f[j] == 2) f[j] = 1;
				else f[j] = 0;
			k += (1<<i);
		}
		else
		{
			for (int j = 1; j <= n; j++) 
				if (f[j] > 0) f[j] = 1;
		}
	}
	printf("%lld",k);
    return 0;
}
