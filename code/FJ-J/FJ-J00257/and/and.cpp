#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,max = 0;
    cin >> n >>m;
	for(long long i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i<=n;i++)
	{
		if(a[i] & a[i+1] > max)
		{
			max = a[i] & a[i+1];
		}
	}
	cout << max;
 } 
