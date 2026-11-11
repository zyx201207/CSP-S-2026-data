#include<bits/stdc++.h>
using namespace std;
int low(int x){return x&-x;}
int sum1(int x)
{
	int ct=0;
	while(x)
	{
		++ct;
		x-=low(x);
	}
	return ct;
}
struct stru
{
	int s1,x1;
}a[200005];
bool cmp(stru a1,stru b1)
{
	if(a1.s1!=b1.s1)return a1.s1>b1.s1;
	else return a1.x1>b1.x1;
}
int n,m,i,j,k,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x1);
		a[i].s1=sum1(a[i].x1);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].x1;
	for(i=2;i<=m;i++)
		ans&=a[i].x1;
	printf("%d\n",ans);
	return 0;
}
