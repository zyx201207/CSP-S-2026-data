#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long ans = 0;
	for (int i = 1;i <=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	long long n1 = n;
	if (n%2==0)
	{
		n1/=2;
	}
	else{
		n1/=2;
		n1++;
	}
	for (int i = n1;i >= 1;i--)
	{
		if (c[i]!=c[n+1-i])
		{
			ans+=min(a[i],a[n+1-i]);
		}
		else{
			if (a[i]!=a[n+1-i])
			{
				if (n1==i)
					ans+=2*abs(a[i]-a[n+1-i]);
				else{
					ans+=abs(a[i]-a[n+1-i]);
				}
			}
		}
	}
	cout <<ans;
} 
