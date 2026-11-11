#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
ll n, m;
ll a[N], need[N], pre[N];
ll ans;
ll maxa;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    bool flag1 = true, flag2 = true;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        maxa = max(maxa, a[i]);
        if(a[i] != i) flag1 = false;
    }
    sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
	{ 
		need[i] = a[i+1] - a[i];
		pre[i] = pre[i-1] + need[i];
	}
	// l 到 r 需要的能量 pre[r-1] - pre[l-1] 
	//期望值45pts 
	if(n <= 5000){
		for(int r = 1; r <= n; r++)
		{
			ll k = m, cnt = 1; 
			for(int l = r - 1; l >= 1; l--)
			{
				ll cost = pre[r-1] - pre[l-1];
				if(k - cost >= 0) cnt++, k -= cost;
				else break;
			}
			ans = max(ans, cnt);
		}
		cout<<ans;
		return 0;
	}
	if(flag1 == true)
	{
		
		ll sum = 0, ans = 1;
		for(int i = 1; i < n; i++)
		{
			if(sum + i <= m) ans++, sum += i;  
			else break;
		} 
		cout<<ans;
	}
	//期望值15pts 
	ll d = a[2] - a[1];
	for(int i = 2; i <= n; i++)
		if(a[i] - a[i-1]!=d)
		{
		    flag2 = false;
		    break;
		}
    if(flag2 == true)
    {
    	ll k = m;
    	ans = 1;
    	for(int l = n - 1; l >= 1; l--)
    	{
    		ll cost = pre[n-1] - pre[l-1];
    		if(k - cost >= 0) ans++, k -= cost;
			else break;
		}
		cout<<ans;
		return 0;
	}
	//期望值15pts 
	return 0;
}
