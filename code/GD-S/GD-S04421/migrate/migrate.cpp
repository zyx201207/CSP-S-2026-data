#include<bits/stdc++.h>
using namespace std;

int c;
int t;
long long n;
long long d;
int in[5000010];
long long temp1, temp2;
long long r;
long long ans = 0;
long long step;
int maxstep;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		temp1 = 0;
		temp2 = 0;
		for(int i = 1; i <= n; i ++)
		{
			temp1 = temp2;
			cin >> temp2;
		}
		step = temp2 - temp1;
		maxstep = d/step;
		if(maxstep == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		
		r = maxstep * 2 - 1;
		for(int i = 1 + maxstep + 1 ; i <= n; i ++)
		{
			r++; 
			ans += (min(r, n) - i + 1);
		}
		cout << ans << '\n';
		ans = 0;
	}
}
