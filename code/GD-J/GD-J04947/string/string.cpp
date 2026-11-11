#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,x[200005],y[200005],sum=0,num=0,sss=0;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> x[i] >> y[i];
		sum+=x[i];
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=x[i]; i++)
		{
			num++;
			if (sum%2==0)
			{
				if (num==sum/2+1)
				{
					if (y[num]!=y[sum-num])
					{
						sss++;
					}
				}
			}
			if (sum%2==1)
			{
				if (num==sum/2+2)
				{
					if (y[num]!=y[sum-num])
					{
						sss++;
					}
				}
			}
		}
	}
	cout << sss;
	return 0;
} 
