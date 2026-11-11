#include <bits/stdc++.h>
using namespace std;

struct aa
{
	long long g;
	char h;
}a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c=0;
	cin>>n;
	long long l=n,k=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].g>>a[i].h;
	}
	for(int i=1;i<=n && i<l;i++)
	{
		while(a[i].g>0)
		{
			if(a[i].g>a[l].g)
			{
				if(a[i].h!=a[l].h)
				{
					c+=a[l].g;
				}
				a[i].g-=a[l].g;
				l--;
			}
			else
			{
				if(a[i].h!=a[l].h)
				{
					c+=a[i].g;
				}
				a[l].g-=a[i].g;
				a[i].g=0;
			}
		}
	}
	cout<<c;
	return 0;
} 
