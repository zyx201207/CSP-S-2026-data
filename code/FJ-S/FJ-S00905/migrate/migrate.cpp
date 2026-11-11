#include <bits/stdc++.h>
using namespace std;
int T,n,d,a[2000005],c,y,p,ans;
void dfs(int r,int s,int x)
{
	if(y>2)
	{
		return;
	}
	if(s==p+1)
    {
	    if(x==r)
	    {
	    	y++;
		}
		return;
    } 
    int i = x + 2;
    while(i<=r)
    {
    	if(a[i] - a[x] > d)
    	{
    		break;
		}
		dfs(r,s+1,i);
		i++;
	}
	dfs(r,s+1,x+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				p = 0;
				for(int k = i; k <= j; k++)
				{
					int o = k;
					int q = d;
					while(q>=a[k+1]-a[k]&&k<j)
					{
						q -= (a[k+1] - a[k]);
						k++;
					}
					if(k==o)
					{
						k++;
					}
					p++;
				}
				if(p>1)
				{
					y = 0;
					dfs(j,1,i);
					if(y==2)
					{
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
