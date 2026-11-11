#include<bits/stdc++.h>
using namespace std;
long long n,ans,n1;
long long a[300005],jds,jdw;
char b[300005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i <= n - 1;i++)
	{
		cin >> a[i] >> b[i];
	}
	if(n % 2 == 1)
	{
		n1 = n / 2 + 1;
	}
	else
	{
		n1 = n / 2;
	}
	while(1)
	{
		if(b[jds] == b[n-1-jdw])//d jd+
		{
			if(a[jds] > a[n-1-jdw])
			{
				a[jds] -= a[n-1-jdw];
				jdw++;
			}
			else if(a[jds] < a[n-1-jdw])
			{
				a[n-1-jdw] -= a[jds];
				jds++;
			}
			else
			{
				jds++;
				jdw++;
			}
		}
		else//c jd+ ans+
		{
			if(a[jds] > a[n-1-jdw])
			{
				a[jds] -= a[n-1-jdw];
				ans += a[n-1-jdw];
				jdw++;
			}
			else if(a[jds] < a[n-1-jdw])
			{
				a[n-1-jdw] -= a[jds];
				ans += a[jds];
				jds++;
			}
			else
			{
				ans += a[jds];
				jds++;
				jdw++;
			}
		}
		if(jds == n-1-jdw)
		{
			break;
		}
		if(abs(jds - (n-1-jdw)) == 1)
		{
			if(b[jds] != b[n-1-jdw])
			{
				ans += a[jds];
			}
			break;
		}
	}
	cout << ans;
	return 0;
}
