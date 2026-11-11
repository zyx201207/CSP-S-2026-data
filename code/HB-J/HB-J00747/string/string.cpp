#include <iostream>
using namespace std;
long long n,a[200005],r;
long long ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	r=n+1;
	for(int l=1;l<=n;l++)
	{
		while(a[l]>0&&r>l)
		{
			if(a[r]<=0)r--;
			if(a[l]>=a[r])
			{
				a[l]-=a[r];
				if(c[l]!=c[r])
				{
					ans+=a[r];
				}
				a[r]=0;
			}
			else
			{
				a[r]-=a[l];
				if(c[l]!=c[r])
				{
					ans+=a[l];
				}
				a[l]=0;
			}
		}
		if(l==r)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}
