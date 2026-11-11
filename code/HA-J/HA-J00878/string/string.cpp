#include<bits/stdc++.h>
using namespace std;
struct qq{
	long long a;
	char b;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	int f=1,l=n;
	long long cnt=0;
	while(f<l)
	{
		if(a[f].b!=a[l].b)
		{
			if(a[f].a<a[l].a)
			{
				cnt+=a[f].a;
				a[l].a-=a[f].a;
				++f;
			}
			else if(a[f].a>a[l].a)
			{
				cnt+=a[l].a;
				a[f].a-=a[l].a;
				--l;
			}
			else
			{
				cnt+=a[f].a;
				++f,--l;
			}
		}
		else
		{
			if(a[f].a<a[l].a)
			{
				a[l].a-=a[f].a;
				++f;
			}
			else if(a[f].a>a[l].a)
			{
				a[f].a-=a[l].a;
				--l;
			}
			else
			{
				++f,--l;
			}
		}
	}
	cout<<cnt;
	return 0;
}
