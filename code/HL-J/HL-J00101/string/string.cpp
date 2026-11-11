#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char b[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int ans=0;
	int l2=1;
	int r2=n;
	int z=0;
	int c1=a[l2];
	int c2=a[r2];
	int flag=0;
	while(1)
	{
		if(b[l2]==b[r2])
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
		if(c1==c2)
		{
			z=c1;
			l2++;
			r2--;
			c1=a[l2];
			c2=a[r2];
		}
		else if(c1<c2)
		{
			z=c1;
			c2-=c1;
			l2++;
			c1=a[l2];
		}
		else
		{
			z=c2;
			c1-=c2;
			r2--;
			c2=a[r2];
		}
		if(flag==0)
		{
			ans+=z;
		}
		if(r2==l2)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
