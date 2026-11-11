#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],sum;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n,cmp);
	sum=a[0];
	for(int i=1;i<m;i++)
		sum=sum&a[i];
	printf("%lld",sum);
	return 0;
}
