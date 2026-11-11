#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,a[500005],b[500005],m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	long long sum = 0,ans = 0,num = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == a[i+1] || a[i] == a[i + 1] - 1)
		{
			sum++;
			if(sum > ans)
			ans = sum;
			num = ans;
		}
		
	}
	long long lyn = 0;
	for(int i = num;i >= 1;i--)
	{
		if(a[i] == a[i-1])
		{
			lyn++;
		}
		else
		{
			break;
		}
	}
	cout << lyn;
	return 0;
}
