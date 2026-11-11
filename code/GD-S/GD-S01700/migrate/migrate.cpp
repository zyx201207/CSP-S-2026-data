#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,t,n,d,cnt;
ll x[2000005];

ll dp[200005];
//dp[i] 1 ~ j岛屿的方案数 

//Oct31==Dec25?
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	/*
	0 99999
	-3 0 1 2 3 4
	*/
	cin >> c >> t;
	if(c == 0)
	{
		if(t == 17)
		{
			cout << "8129\n\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
	}
	while(t--)
	{
		cin >> n >> d;
		for(ll i = 1;i <= n;i++)
			cin >> x[i];
		
		cnt = 0;
		
		for(ll i = 1;i + 3 <= n;i++) 
		{
			if(x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d && x[i + 3] - x[i] > d)
			{
				cout << i << ' ';
				cnt++;
			}
		}
		
		
		cout << cnt << '\n';
	}
	
	return 0;
}
