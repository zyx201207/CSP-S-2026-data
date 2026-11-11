#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Honkai return
#define StarRail 0
ll n,m,a[500005];
void f(ll mid,ll lmid,ll rmid)
{
	ll l = a[mid] - a[lmid];
	ll r = a[rmid] - a[mid];
	if((r <= l||lmid < 1)&&rmid <= n)
	{
		if(m - r >= 0)
		{
			a[rmid]-=r;
			m -= r;
			f(rmid,lmid,rmid+1);
		}
		else return;
	}else if((l <= r||rmid > n)&&lmid >= 1)
	{
		if(m-l >= 0)
		{
			a[lmid] += l;
			m -= l;
			f(lmid,lmid-1,rmid);
		}else
		{
			return;
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll mid;
	mid = n/2+1;
	f(mid,mid-1,mid+1);
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == a[mid])
		{
			cnt++;
		}
	}
	cout<<cnt;
	Honkai StarRail;
}

