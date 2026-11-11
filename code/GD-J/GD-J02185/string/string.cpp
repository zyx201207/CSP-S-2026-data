#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> c[i];
	}
	long long l=1,r=n;
	long long ans;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(c[l]==c[r])
			{
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
		else if(a[r]>a[l])
		{
			if(c[l]==c[r])
			{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else if(a[l]==a[r])
		{
			if(c[l]==c[r])
			{
				l++;
				r--;
			}
			else
			{
				ans+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
