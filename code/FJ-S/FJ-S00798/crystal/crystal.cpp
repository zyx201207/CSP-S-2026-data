#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
int n; LL m;
LL a[N], pre[N];


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
	cin >> n >> m;
	if(n == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
		
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	/*
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		LL res = 1ll * (i - 1) * a[i] - pre[i - 1]; 
		if(res <= m) ans = i;
		else break;
	}
	*/
	
	int ans = 0;
	for(int i = 2, l = 1; i <= n; i++)
	{
		LL res = (1ll * i - l) * a[i] - (pre[i - 1] - pre[l - 1]);
		while(res > m) 
		{
			l ++;
			res = (1ll * i - l) * a[i] - (pre[i - 1] - pre[l - 1]);
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
