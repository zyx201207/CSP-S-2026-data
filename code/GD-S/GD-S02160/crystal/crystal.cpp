#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n,ans;
ll m,sum,a[N];
queue <int> q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	a[0] = a[1];
	for(int i = 1;i <= n;i++)
	{
		sum += q.size() * (a[i] - a[i - 1]);
		q.push(i);
		while(!q.empty() && sum > m)
		{
			sum -= (a[i] - a[q.front()]);
			q.pop();
		}
		ans = max(ans,(int)(q.size()));
	}
	cout << ans;
	return 0;
}
