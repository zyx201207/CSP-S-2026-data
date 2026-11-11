#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,ans;
int x[2000010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i ++)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 2*d;j <= n;j++)
			{
				if(j-i+1 == 2*d)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0; 
}
