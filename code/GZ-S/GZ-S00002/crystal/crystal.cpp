//GZ-S00002 утсю╨Г 
#include <bits/stdc++.h>
using namespace std;
const int e= 1e6+5;
long long int n,m,d,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> n >> m;
	long long int a[100000],c[100000];
	int max = 100000000;
	for(int i =0;i<n;i++)
	{
		a[i] = 0;
		c[i] = 0;
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i =0;i<n;i++) 
	{
		for(int j =0;j<n;j++)
		{
			c[i] += abs(a[i] - a[j]);
			
		}
		if(max >= c[i]) 
		{
			max = c[i];
			d = i;
		}
	}
	max = a[d];
	for(int i = d;i>=0;i--)
	{
		if(max != a[i])
		{
			if(m <=0)
			{
				break;
			}
			m -= max-a[i];
			a[i] += max-a[i];
		}
	}
	for(int i =0;i<n;i++)
	{
		if(a[i] == max) sum++;
	}
	cout << sum;
	return 0;
}
