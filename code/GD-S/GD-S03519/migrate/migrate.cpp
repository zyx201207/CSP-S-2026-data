#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e6+10;

int c, T;

ll n, m;
ll a[MAXN];

pair<int, int> d[MAXN];

ll ans;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>c>>T;
	while(T--)
	{
		ans = 0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int b=1;b<=n;b++)
		{
			d[b] = {0, 1};
			for(int i=b+1;i<=n;i++)
			{	
				d[i] = {1e9, 0};
				for(int f=i-1;f>=b;f--)
				{
					if(a[i] - a[f] > m) break;
					if(d[f].first + 1 == d[i].first) d[i].second += d[f].second;
					if(d[f].first + 1 < d[i].first) d[i].first = d[f].first + 1, d[i].second = d[f].second;
				}
				ans += (d[i].second == 2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
