#include<bits/stdc++.h>
using namespace std;
struct aa
{
	long long a;
	int b;
}z[500005];
long long n,m,x[500005],za[500005],zb[500005],tot = 0,l,r,mid,ans,t;
map<long long,int> xi;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i];
		xi[x[i]]++;
	}
	for(auto i : xi)
	{
		tot++;
		z[tot] = {i.first,i.second};
	}
	for(int i = tot;i >= 1;i--)
	{
		za[i] = za[i+1]+z[i].b*(z[tot].a-z[i].a);
		zb[i] = zb[i+1]+z[i].b;
	}
	t = z[1].b;
	for(int i = 2;i <= tot;i++)
	{
		l = 1;
		r = i-1;
		ans = -1;
		while(l <= r)
		{
			mid = (l+r)/2;
			if(za[mid]-za[i]-(zb[mid]-zb[i])*(z[tot].a-z[i].a) >= m)
			{
				ans = mid;
				l = mid+1;
			}
			else
			{
				r = mid-1;
			}
		}
		if(ans != -1)
		{
			t = max(t,zb[ans+1]-zb[i+1]+(m-(za[ans+1]-za[i])+(zb[ans+1]-zb[i])*(z[tot].a-z[i].a))/(z[i].a-z[ans].a));
		}
		else
		{
			t = max(t,zb[1]-zb[i+1]);
		}
	}
	cout << t;
	return 0;
}
