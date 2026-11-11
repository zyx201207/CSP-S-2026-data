#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n,m,temp;
	vector<ll> a(n+1);
	cin>>n;
	cin>>m;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	for(int i = 0;i < n-1;i++)
	{
		for(int j = 0;j < n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	int cnt = 0;
	int ans = 0;
	for(int i = n-1;i >= 0;i--)
	{
		ll sum = 0;
		int cnt = 0;
		for(int j = i;j > 0;j--)
		{
			sum += (a[i]-a[j-1]);
			cnt++;
			if(sum == m && cnt > ans)
			{
				ans = cnt;
				continue;
			}	
		}
	}
	ans = ans+1;
	cout<<ans<<endl;
	return 0;
}
