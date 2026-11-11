#include<iostream>
#include<algorithm>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	if(m==2&&n<=10000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		sort(a+1,a+1+n);
		cout<<a[(n-m+1)]<<endl;
	}
	return 0;
}
