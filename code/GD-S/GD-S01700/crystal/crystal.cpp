#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,ans,maxx,minx;
ll a[500005];

//假设我们尽量把数组排成x。 
ll chk(ll x)
{
	ll cnt = m,num = 0;
	ll xl = 1,xr = n;
	while(xl <= xr)
	{
		ll mid = (xl + xr) / 2;
		if(a[mid] <= x)xl = mid + 1;
		else xr = mid - 1;
	}
	ll pos = xr;
	for(int i = pos;i >= 1;i--)
	{
		if(a[i] > x)continue; 
		if(a[i] == x)
		{
			//cout << i << " ";
			num++;
			continue;
		}
		if(cnt < x - a[i])
		{
			break;
		}
		else
		{
			//cout << i << " ";
			cnt -= (x - a[i]);
			//a[i] = m;
			num++;
		}
	}
	//cout << endl;
	return num;
}
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >> n >> m;
	
	//Oct31==Dec25?
	ans = -1e18;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxx = max(a[i],maxx);
		minx = min(a[i],minx);

	}
		
	sort(a + 1,a + n + 1);
	
	ll maxnum = -1e18;
	for(ll i = minx;i <= maxx;i++)
	{
		//cout << i << " " << " " << chk(i) << "\n";
		maxnum = max(maxnum,chk(i));
	}
	
	cout << maxnum;
	return 0;	
} 
