#include<bits/stdc++.h>
using namespace std;
long long n,sum,tot,ans;
long long l1,r1;
char x;
struct xty
{
	long long a;
	char x;
}a[2000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[++tot].a;
		cin>>a[tot].x;
		sum+=a[tot].a;
		if(a[tot].x==a[tot-1].x)
		{
			tot--;
			a[tot].a+=a[tot+1].a;
		}
	}
	l1=1;
	r1=tot;
	while(l1<r1)
	{
		if(a[l1].x!=a[r1].x)
			ans+=min(a[l1].a,a[r1].a);
		if(a[l1].a>a[r1].a)
		{
			a[l1].a-=a[r1].a;
			r1--;
		}
		else if(a[r1].a>a[l1].a)
		{
			a[r1].a-=a[l1].a;
			l1++;
		}
		else
		{
			r1--;
			l1++;
		}
	}
	cout<<ans;
	return 0;
} 
