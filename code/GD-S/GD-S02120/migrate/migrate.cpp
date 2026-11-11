#include <iostream>
#include <cstring>
using namespace std;
int c,t,n,d,a[2000005],cnt[2000005],ct[50005][505];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		memset(cnt,0,sizeof(cnt));
		memset(ct,0,sizeof(c));
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j < i;j++)
			{
				if(a[i] - a[j] <= d)
				{
					cnt[i] = max(cnt[i],cnt[j] + 1),ct[cnt[i]][i]++;
					if(ct[cnt[i]][i] == 2) ans++;
					cout << ct[cnt[i]][i] << " ";
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
