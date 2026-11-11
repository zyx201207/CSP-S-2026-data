#include <bits/stdc++.h>
using namespace std;

char c[200005];
int n;
long long a[200005],ans = 0,l,r,cl,cr;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)	cin >> a[i] >> c[i];
	l = 1;
	r = n;
	cl = a[1];
	cr = a[n];
	while(l <= r)
	{
		if(cl > cr)
		{
			if(c[l] != c[r])	ans += cr;
			r--;
			cl -= cr;
			cr = a[r];
		}
		else if(cl < cr)
		{
			if(c[l] != c[r])	ans += cl;
			l++;
			cr -= cl;
			cl = a[l];
		}
		else if(cl == cr)
		{
			if(c[l] != c[r])	ans += cl;
			l++;
			r--;
			cl = a[l];
			cr = a[r];
		}
		if(l == r)	break;
	}
	cout << ans << endl;
	return 0;
}
