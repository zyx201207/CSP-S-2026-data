#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
bool book[20005][20005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld",&a[i]);	
		}
		for(int i = 1;i <= n;i++)
		{
			if(a[i]-a[i-1] > d)
			{
				for(int j = i;j <= n;j++)
				{
					a[j] = a[j+1];
				}
				i--;
				n--;
			}
		}
		for(int i = 2;i < n-1;i++)
		{
			if(a[i+2]-a[i] >= d)
			{
				for(int x = 1;x <= i;x++)
				{
					for(int y = i+2;y <= n;y++)
					{
						if((a[y]-a[x])%2 == 1&&book[x][y] == 0&&book[y][x] == 0)
						{
							book[x][y] = 1;
							book[y][x] = 1;
							ans++;
						}
					}
				}
			}
			i+=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//☭RP++
