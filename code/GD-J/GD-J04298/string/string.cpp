#include<bits/stdc++.h>
using namespace std;
struct f{
	long long a;
	char b;
}a[200005];
int n;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	int m=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i].b!=a[m].b)
		{
			if(a[i].a>a[m].a)
			{
				ans+=a[m].a;
			}
			else
			{
				ans+=a[i].a;
			}
		}
		else
		{
			if(a[i].a!=a[m].a)
			{
				if(a[i+1].b==a[i].b || a[m-1].b==a[m].b)
				{
					if(a[i+1].b==a[i].b && a[i].a>a[m].a)
					{
						a[i+1].a+=a[i].a-a[m].a;
						a[i].a=a[m].a;
					}
					if(a[m-1].b==a[m].b && a[m].a>a[i].a)
					{
						a[m-1].a+=a[m].a-a[i].a;
						a[m].a=a[i].a;
					}
				}
				else
				{
					ans+=abs(a[m].a-a[i].a);
					if(a[m].a>a[i].a)
					{
						a[m-1].a+=a[m].a-a[i].a;
					}
					else
					{
						a[i+1].a+=a[i].a-a[m].a;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
