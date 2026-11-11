#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x[10000],y[10000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long s=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		int g1=0,g2=0,d=1;
		for(;s>0;s=s/2) x[++g1]=s%2;
		for(;a[i]>0;a[i]=a[i]/2) y[++g2]=a[i]%2;
		s=0;
		for(int j=1;j<=min(g1,g2);j++)
		{
			if(x[j]==1&&y[j]==1) s=s+d;
			d=d*2;
		}
	}
	printf("%lld",s);
	return 0;
}
