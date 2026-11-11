#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m;
int a[N],c[N];
int s=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	sort(a,a+n);
	int l=0,r=n-1;
	int mid=(l+r)/2;
	for(int i=mid-1;i>=0;i)
	{
		if(m<0)break;
			c[i]+=a[mid]-a[i];
			m-=a[mid]-a[i];
			i--;
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]==c[mid])s++;
	}
	printf("%d\n",s);
	return 0;
}
