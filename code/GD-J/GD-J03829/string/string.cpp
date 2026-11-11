#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,id;
struct lx
{
	int num;
	char c;
}te[200005],sz[200005];
int ef(int a)
{
	int l = 0,r = id,mid;
	while (l + 1 < r)
	{
		mid = l+(r-l)/2;
		if (sz[mid].num < a)
			l = mid;
		else
			r = mid;
	}
	return r;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ai,temp(0),mid,sum(0);
	char ci;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> te[i].num >> te[i].c;
		sum += te[i].num;
	}
	mid = sum/2;
	if (sum <= 1e7)
	{
		string s = "";
		int ans(0);
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= te[i].num;j++)
				s += te[i].c;
		}
//		cout << s;
		for (int i = 0;i <= mid-1;i++)
		{
			if (s[i] != s[sum-i-1])
				ans++;
		}
		cout << ans;
		
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		temp += te[i].num;
		if ((i < n) && te[i].c != te[i+1].c)
		{
			id++;
			sz[id].num = temp,sz[id].c = te[i].c;
		}
	}
	sz[0].num = 0;
	int ans(0);
	id++;
	sz[id].num = temp,sz[id].c = te[n].c;
	int qian(id),t,js,jl;
	for (int i = 1;sz[i].num <= mid;i++)
	{
		t = ef(sum-sz[i].num+1);
		js = sz[i].num;
		jl = i;
		for (int j = qian;j >= t;j--)
		{
			if (sz[i].c != sz[j].c)
			{
				ans += sz[j].num-sz[j-1].num;
//				if (sz[j].num <= sum-sz[i-1].num && sz[j-1].num >= sum-sz[i].num)
//					
				if (sz[j].num > (sum-sz[i-1].num))
					ans -= sz[j].num-sum+sz[i-1].num;
				if (sz[j-1].num < (sum-sz[i].num))
					ans -= sum-sz[i].num-sz[j-1].num;
			}	
		}
		qian = t;
		if (sum-sz[i].num == sz[t-1].num)
			qian--;
	}
	if (js < mid)
	{
		t = ef(sum-mid+1);
		for (int j = qian;j >= t;j--)
		{
			if (sz[jl+1].c != sz[j].c)
			{
				ans += sz[j].num-sz[j-1].num;
//				if (sz[j].num <= sum-sz[i-1].num && sz[j-1].num >= sum-sz[i].num)
//					
				if (sz[j].num > (sum-sz[jl].num))
					ans -= sz[j].num-sum+sz[jl].num;
				if (sz[j-1].num < (sum-sz[jl+1].num))
					ans -= sum-sz[jl+1].num-sz[j].num;
			}	
		}
	} 
	cout << ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
