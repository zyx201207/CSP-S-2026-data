#include<bits/stdc++.h>
using namespace std;
int n,x=1,y;
char b[200005];
long long a[200005],l=1,r=1,s=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	y=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]='0';
		while(b[i]<'a'||b[i]>'z')
		{
			scanf("%c",&b[i]);
		}
	}
	while(x<y)
	{
		long long f=min(a[x]-l+1,a[y]-r+1);
		if(b[x]!=b[y])
		{
			s+=f;
		}
		l=l+f;
		r=r+f;
		if(l>a[x])
		{
			x++;
			l=1;
		}
		if(r>a[y])
		{
			y--;
			r=1;
		}
	}
	printf("%lld",s);
	return 0;
}
