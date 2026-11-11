#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+5;
long long a[N],n,m,maxi = INT_MIN,sum = 0,ans = INT_MIN;
bool vis[N];
void ab(long long x,long long dep,long long su)
{
	if(dep>x)
	{
		ans = max(ans,su);
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			if(dep==1)
			{
				su = a[i];
				ab(x,dep+1,su);
			}
			else
			{
				ab(x,dep+1,su&a[i]);
			}
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		maxi = max(maxi,a[i]);
		if(i==1)
		{
			sum = a[i];
		}
		else
		{
			sum = sum&a[i];
		}
	}
	if(m==1)
	{
		cout<<maxi;
		return 0;
	}
	if(m==n)
	{
		cout<<sum;
		return 0;
	}
	ab(m,1,0);
	cout<<ans;
	return 0;
}