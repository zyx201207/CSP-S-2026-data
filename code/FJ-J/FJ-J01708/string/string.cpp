#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int MAXN = 2e5+5;
pair<ll,char> a[MAXN];

ll read()
{
	ll res = 0;
	bool f = 0;
	char tc = getchar();
	while(tc < '0' || tc > '9')
	{
		if(tc == '-') f = 1;
		tc = getchar();
	}
	while(tc >= '0' && tc <= '9')
	{
		res = (res<<1)+(res<<3)+(tc^48);
		tc = getchar();
	}
	return f?-res:res;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n = read();
	ll sum = 0;
	for(int i = 0;i < n;i++)
	{
		a[i].fi = read();
		cin>>a[i].se;
		sum += a[i].fi;
	}
	
	int l = 0,r = n-1;
	ll lp = 1,rp = sum,cnt = 0,nrcnt = a[r].fi,nlcnt = a[l].fi;

	lp += a[l].fi-1;
	rp -= a[r].fi-1;
	while(l < r)
	{
		if(lp > sum-rp+1) 
		{
			if(a[l].se != a[r].se)
				cnt += nrcnt;
			nlcnt -= nrcnt;
			rp -= a[--r].fi;
			nrcnt = a[r].fi;
		}
		else if(lp < sum-rp+1)
		{
			if(a[l].se != a[r].se)
				cnt += nlcnt;
			nrcnt -= nlcnt;
			lp += a[++l].fi;
			nlcnt = a[l].fi;
		}
		else 
		{
			if(a[l].se != a[r].se)
				cnt += nrcnt;
			lp += a[++l].fi;
			rp -= a[--r].fi;
			nlcnt = a[l].fi;
			nrcnt = a[r].fi;
		}
	}
	
	cout<<cnt<<endl;
	return 0;
}
/*
2
2 a
3 a

3
2 a
2 b
1 c

3
1 a
2 b
2 c

3
5 a
4 c
2 b

7
1 a
1 b
1 c
1 d
1 e
1 f
1 g
*/
