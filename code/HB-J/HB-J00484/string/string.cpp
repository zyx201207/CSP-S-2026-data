#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a[n+1] = {0};
	char c[n+1];
	for(long long i = 1;i<=n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	long long l = 1;
	long long r = n;
	long long sum=0;
	while(r > l)
	{
		if(c[l]!=c[r])
		{
			long long x = min(a[l],a[r]);
			if(c[l]==x&&c[r]!=x)
			{
				sum+=x;
				a[l]-=x,a[r]-=x;
				l++;
			}
			else if(c[l]!=x&&c[r]==x)
			{
				sum+=x;
				a[l]-=x,a[r]-=x;
				r--;
			}
			else
			{
				sum+=x;
				a[l]-=x,a[r]-=x;
				l++,r--;
			}
		}
		else
		{
			long long x = min(a[l],a[r]);
			if(c[l]==x&&c[r]!=x)
			{
				a[l]-=x,a[r]-=x;
				l++;
			}
			else if(c[l]!=x&&c[r]==x)
			{
				a[l]-=x,a[r]-=x;
				r--;
			}
			else
			{
				a[l]-=x,a[r]-=x;
				l++,r--;
			}
		}
	}
	cout << sum;
	return 0;
}
//2 2 1
//a b c
//l   r
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
