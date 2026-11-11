#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[200005],ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
