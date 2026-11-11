#include<bits/stdc++.h>
using namespace std;
int a[200001],m,n,s,t;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=30;i>=0;i--)
	{
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		t=0;
		for(int j=1;j<=n;j++)if((a[j]>>i)&1)t++;
		if(t>=m)n=t,s+=1<<i;
		for(int j=1;j<=n;j++)a[j]&=(1<<i)-1;
	}
	printf("%d",s);
	return 0;
}
