#include<bits/stdc++.h>
using namespace std; 
//注意到对于一个最靠左的牌，如果右边有一样的，那么一定会收 
//倒过来，记一下每次多出哪张，最后往后推
//感觉会爆 int 保险起见开 longlong 
//调对了，那我也许AK了？

const int N = 500005;

int n, m, a[N];
int lst[N], nw[N], nxt[N];
long long ans[N], cnt[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = n; i >= 1; i--)
	{
		nxt[i] = nw[a[i]];
		nw[a[i]] = i;
	}
	for(int i = n; i >= 1; i--)
	{
		if(!lst[a[i]])lst[a[i]] = i;
		cnt[i] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		if(i != lst[a[i]])
		{
			cnt[lst[a[i]]] += cnt[i];
			cnt[i] = 0;
		}
		else
		{
			ans[a[i]] += cnt[i];
			cnt[i + 1] += cnt[i];
			cnt[i] = 0;
		}
	}
	for(int i = 1; i <= m; i++)cout << ans[i] << ' ';
	
	return 0;
}  
