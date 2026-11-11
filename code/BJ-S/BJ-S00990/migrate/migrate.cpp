#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N =  2e6 + 7;

int c, T;
int n, d, x[N], l[N][30], r[N][30];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		
		if(c == 11 || c == 12)
		{
			int t = d / (x[2] - x[1]);
			int ans = 0;
			for(int i=1;i<= n;i++)
			{
				int nxt = i+t-1 -1;
				if(nxt+t-1 <= n) ans ++;
			}
			for(int i=n;i>=1;i--)
			{
				int lst = i-t+1 +1;
				if(lst-t+1 >= 1) ans ++;
			}
			cout<<ans<<"\n";
			continue;
		}
		
		for(int i=1;i<=n;i++)
		{
			l[i][0] = lower_bound(x+1, x+n+1, x[i]-d) - x;
			r[i][0] = upper_bound(x+1, x+n+1, x[i]+d) - x - 1;
			//cout<<i<<" "<<l[i][0]<<" "<<r[i][0]<<"\n";
		}
		
		for(int j=1;j<=25;j++)
			for(int i=1;i<=n;i++)
			{
				l[i][j] = l[l[i][j-1]][j-1];
				r[i][j] = r[r[i][j-1]][j-1];
			}
		
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int pos = 0;
				for(int k=25;k>=0;k--)
					if(r[i][k] < x[j])
					{
						pos = k;
						break;
					}
				//cout<<i<<" "<<j<<" "<<pos<<"\n";
				int L = l[j][pos];
				int R = r[i][pos];
				
				if(L < R && R - L == 1) ans ++;
			}
		}
		cout<<ans<<"\n";
		
	}
	
	return 0;
}
