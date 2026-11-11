#include<bits/stdc++.h>
using namespace std;
const int b = 2e6+5;
long long n,m,a[b],ans,temp;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0;i < n;i++)
	{
		if(a[i] == a[i+1])
		{
			a[i] = 0;
			a[i+1] = 0;
			temp++;
			ans++;
		}
	}
	sort(a,a+n);
	sort(a+temp,a+n);
	for(int c = m;c > 0;c--)
	{
		for(int i = 0;i < n-temp;i++)
		{
			if((a[i]+c) == a[i+1])
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
