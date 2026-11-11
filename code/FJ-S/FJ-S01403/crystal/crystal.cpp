#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int MAXN = 5e5+5;
ll a[MAXN] = {0},s[MAXN] = {0};

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
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll n = read(),m = read();
	for(int i = 0;i < n;i++) a[i] = read();
	sort(a,a+n);
	s[0] = a[0];
	for(int i = 1;i < n;i++) s[i] = s[i-1]+a[i];
	
	int max_ = -1;
	for(int i = 0;i < n;i++)
	{
		int l = 0,r = i;
		while(l <= r)
		{
			int mid = (l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-(mid?s[mid-1]:0)) > m) l = mid+1;
			else r = mid-1;
		}
		max_ = max(max_,i-l+1);
	}
	cout<<max_;
	return 0;
}

/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/
