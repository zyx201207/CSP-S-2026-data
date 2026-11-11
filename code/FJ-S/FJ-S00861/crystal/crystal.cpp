#include <iostream>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int a[5000005];
int cha[5000005];
int s[5000005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool f = 1;
	for(int i = 1 ; i <= n ; i ++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1 ; i <= n ; i ++)
	{
		cha[i] = a[i] - a[i-1];
		if(i == 1) cha[i] = 0;
		else
		{
			if(cha[i] != cha[i-1])f = 0;
		}
	}
	if(f)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			if((i+1)*i/2*cha[2] >m)
			{
				cout<<i;
				return 0;
			}
		}
	}
	int ans = 0,temp = 0;
	int l = 2,r = 2;
	int use = 0;
	queue <int> q;
	while(r <= n)
	{
		if(l > r)
		{
			l ++;
			r ++;
			continue;
		}
		if(n - l + 1 < ans) break;
		int use = 0;
		int cnt = 1;
		for(int i = l ; i <= r ; i ++)
		{
			use += cnt * cha[i];
			cnt++;
		}
		if(use <= m)
		{
			r ++;
			temp ++;
			ans = max(ans,temp);
		}
		else
		{
			l ++;
			temp--;
		}
	}	
	cout<<ans + 1;
	return 0;
}
