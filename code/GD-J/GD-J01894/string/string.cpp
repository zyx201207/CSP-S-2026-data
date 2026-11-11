#include<bits/stdc++.h>
using namespace std;
int n , a[200005];
char c[200005];
long long sum;
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] >> c[i];
	int l = 1 , r = n;
	while(l < r)
	{
		if(l >= r) break;
		if(a[l] > a[r])
		{
			a[l] -= a[r];
			r --;
			if(c[l] != c[r])
			{
				sum += a[r];
			}
		}
		else if(a[l] == a[r])
		{
			l ++;
			r --;
			if(c[l] != c[r])
			{
				sum += a[r];
			}
		}
		else
		{
			a[r] -= a[l];
			l ++;
			if(c[l] != c[r])
			{
				sum += a[l];
			}
		} 
	}
	cout << sum;
	return 0;
}
