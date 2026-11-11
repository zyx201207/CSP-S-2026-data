#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nn
{
	ll x,cnt=0;
}a[200005];
bool cmp(nn a,nn b)
{
	if(a.cnt==b.cnt) return a.x>b.x;
	else return a.cnt>b.cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin >> n >>m;
	for(int i = 1;i <= n;i++)
	{
		ll y;
		cin >> y;
		a[i].x=y;
		while(y)
		{
			if(y&1) a[i].cnt++;
			y>>=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	ll ans = a[1].x;
	for(int i = 1;i <= m;i++)
	{
		ans=ans&a[i].x;
	}
	cout << ans;
	return 0;
}
