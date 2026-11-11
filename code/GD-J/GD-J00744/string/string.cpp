#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long l,r,ch;
	char d;
}a[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	long long t;
	cin >> t;
	for (int i = 1;i <= t; i++)
	{
		long long x;
		char y;
		cin >> x >>y;
		a[i].ch = x;
		a[i].l = a[i-1].r+1;
		a[i].r = a[i-1].r+x;
		a[i].d = y;
	}
	
	long long  cnt = 0;
	long long l = 1,r = t;
	long long llw = 1,lrw = a[1].r;
	long long rlw = a[r].l,rrw = a[r].r;
	while(l <= r)
	{
		long long lenl = lrw - llw +1;
		long long lenr = rrw - rlw +1;
		if (lenl == lenr)
		{
			if (a[l].d != a[r].d) cnt += lenl;
			l++;
			r--;
			llw = a[l].l;
			lrw = a[l].r;
			rlw = a[r].l;
			rrw = a[r].r;
		}
		else if (lenl > lenr)
		{
			if (a[l].d != a[r].d) cnt += lenr;
			r--;
			rlw = a[r].l;
			rrw = a[r].r;
			llw = lrw-(lenl - lenr)+1;
		}
		else if (lenl < lenr)
		{
			if (a[l].d != a[r].d) cnt += lenl;
			l++;
			llw = a[l].l;
			lrw = a[l].r;
			rrw = rlw+(lenr-lenl)-1;
		}
	}
	cout << cnt;
	return 0;
 } 
