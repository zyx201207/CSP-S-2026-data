#include<bits/stdc++.h>
using namespace std;

int n;
long long m,ans;
long long a[500010];

long long f(int midd)
{
	long long sum = 0;
	for(int i = 1;i <= midd;i++)
	{
		sum += a[midd]-a[i];
	}
	return sum;
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
	
	int l = 1,r = n;
	while(l <= r)
	{
		int mid = r-(r-l)/2;
		if(f(mid) == m)
		{
			ans = mid;
			break;
		}
		else if(f(mid) < m)
		{
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	long long pos = ans;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == a[ans])
		{
			pos++;
		}
	}
	cout << pos-1;
	
	return 0; 
}
