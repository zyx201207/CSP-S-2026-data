#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define TIII tuple<int,int,int>
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define il inline
#define rg register
#define fi first
#define se second
#define MAXN 200005
using namespace std;
int n,a[MAXN],c[MAXN],sum,ans = 0;
vector<PII> l,r;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (rg int i = 1;i<=n;i++)
	{
		char x;
		cin>>a[i]>>x;
		c[i] = x - 'a' + 1;
		sum += a[i];
	}
	l.PB(MP(-1,-1)),r.PB(MP(-1,-1));
	if (sum % 2)
	{
		int w = (sum + 1) / 2;
		for (rg int i = 1,tmp = 0;i<=n;i++)
		{
			if (tmp == w - 1) break;
			if (tmp + a[i] <= w - 1)
			{
				l.PB(MP(a[i],c[i]));
				tmp += a[i];
			}
			else if (tmp + a[i] > w - 1)
			{
				l.PB(MP(w - tmp - 1,c[i]));
				tmp = w - 1;
			}
		}
		for (rg int i = n,tmp = 0;i>=1;i--)
		{
			if (tmp == w - 1) break;
			if (tmp + a[i] <= w - 1)
			{
				r.PB(MP(a[i],c[i]));
				tmp += a[i];
			}
			else if (tmp + a[i] > w - 1)
			{
				r.PB(MP(w - tmp - 1,c[i]));
				tmp = w - 1;
			}
		}
	}
	else
	{
		int w = sum / 2;
		for (rg int i = 1,tmp = 0;i<=n;i++)
		{
			if (tmp == w) break;
			if (tmp + a[i] <= w)
			{
				l.PB(MP(a[i],c[i]));
				tmp += a[i];
			}
			else if (tmp + a[i] > w)
			{
				l.PB(MP(w - tmp,c[i]));
				tmp = w;
			}
		}
		for (rg int i = n,tmp = 0;i>=1;i--)
		{
			if (tmp == w) break;
			if (tmp + a[i] <= w)
			{
				r.PB(MP(a[i],c[i]));
				tmp += a[i];
			}
			else if (tmp + a[i] > w)
			{
				r.PB(MP(w - tmp,c[i]));
				tmp = w;
			}
		}
	}
	for (rg int i = 1,j = 1;i<=l.size()-1&&j<=r.size()-1;)
	{
		int x1 = l[i].fi,x2 = l[i].se,x3 = r[j].fi,x4 = r[j].se;
		if (x1 == x3)
		{
			if (x2 != x4) ans += x1;
			i ++,j ++;
		}
		else if (x1 < x3)
		{
			if (x2 != x4) ans += x1;
			r[j].fi -= x1;
			i ++;
		}
		else
		{
			if (x2 != x4) ans += x3;
			l[i].fi -= x3;
			j ++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
