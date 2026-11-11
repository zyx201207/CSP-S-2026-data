#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,l,r,cnt,lcnt,rcnt;
ll a[200005],s[200005];
char c[200005];


int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
	}
	
	l = 1,r = n;
	lcnt = a[l],rcnt = a[r];
	while(l < r)
	{
		//cout << l << " " << r << endl;
		if(c[l] != c[r])
		{
			cnt += min(lcnt,rcnt); 
		}
		
		if(lcnt == rcnt)
		{
			l++,r--;
			lcnt = a[l],rcnt = a[r];
		}
		else if(lcnt < rcnt)
		{
			rcnt -= lcnt;
			l++;
			lcnt = a[l];
		}
		else
		{
			lcnt -= rcnt;
			r--;
			rcnt = a[r];
		}
	}
	/*
	l = 1,r = s[n];
	l = 
	while(l < s[n] / 2 && r > s[n] / 2)
	{
		cout << l << " " << r << endl;
		
		ll al = chk(l);
		ll ar = chk(r);
		//l在第al个区间， r在第ar个区间 
		//区间al范围s[al - 1] + 1 ~ s[al] 
		if(c[al] != c[ar])
		{
			cnt += min(l - lt(al) + 1,rt(ar) - r + 1);
		}
		ll goon = min(rt(al) - l + 1] + 1,r - lt(r) + 1);
		cout << goon << endl;
		l += goon,r -= goon;
	}
	*/
	//密码：Trick||Treat!
	
	cout << cnt;
	
	return 0;
}
