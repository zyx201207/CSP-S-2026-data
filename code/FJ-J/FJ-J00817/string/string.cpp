#include<bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;
int a[200010][3], n, l, r;
ll s, m, h, k;
void solve()
{
	cin>>n;
	char x;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i][1]>>x;
		a[i][2] = x;
		m += a[i][1];
	}
	r = n;
	l = 1;
	while(l < r && (h <= m / 2 || k <= m / 2))
	{
		if(a[l][1] == a[r][1])
		{
			h += a[l][1];
			k += a[r][1];
			if(a[l][2] != a[r][2]) s += a[l][1];
			r--;
			l++;
		}
		else if(a[l][1] > a[r][1]) 
		{
			k += a[r][1];
			a[l][1] -= a[r][1];
			if(a[l][2] == a[r][2])
				r--;
			else
			{
				s += a[r][1];
				r--;
			}
		}
		else if(a[l][1] < a[r][1])
		{
			h += a[l][1];
			a[r][1] -= a[l][1];
			if(a[l][2] == a[r][2])
				l++;
			else
			{
				s += a[l][1];
				l++;
			}
		}
	}
	cout<<s;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}

