#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m,a[100000],sum,sum2=1,sum3,num=0,maxn=-1;
    cin >> n >> m;
    if (m == 2)
    {
    	sum = n*(n-1)/2;
	}
	else
	{
		sum = (n-m+2)*(n-m+1)/2;
		for (int i = n;i < m-2+n;i++)
		{
			sum *= i;
		}
	}
	sum3 = sum * sum2;
    for (int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	for (int i = 1;i < n;i++)
	{
		for (int j = i+1;j <= n;j++)
		{
			int t = a[i] and a[j];
			cout << t << " ";
			maxn = max(maxn,t);
		}
	}
	cout << maxn;
	return 0;
} 
