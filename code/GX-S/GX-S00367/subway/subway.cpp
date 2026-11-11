#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int c,n,m,d,q,sum,ans;
int ex[500001];
struct bzd
{
	int zh,ti;
};
struct sub
{
	int k;
	bzd one[500001];
}a[501];
bool cmp(bzd a,bzd b)
{
	return a.zh<b.zh;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d\n",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d ",ex+i);
	for(int i=1;i<=n;i++)
	{
		scanf("%d ",&a[i].k);
		for(int j=1;j<=a[i].k;j++) scanf("%d %d",&a[i].one[j].zh,&a[i].one[j].ti);
		sort(a[i].one+1,a[i].one+a[i].k+1,cmp);
	}
	for(int t=1;t<=q;t++)
	{
		int x,y;
		scanf("%d %d\n",&x,&y);
		sum=ex[x]+a[x].one[1].ti;
		printf("%d\n",sum*(y-x));
	}
	return 0;
}
