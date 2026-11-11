#include<bits/stdc++.h>
using namespace std;
char c[200000];
int a[200000],b,n;
long long d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%s",&a[i],&c[i]);
	for(int l=0,r=n-1;l<r;)
	{
		if(a[l]>a[r])b=a[r];
		else b=a[l];
		if(c[l]!=c[r])d+=b;
		a[l]-=b,a[r]-=b;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	printf("%lld",d);
	return 0;
}
