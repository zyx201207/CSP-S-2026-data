#include<bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i=l;i<=r;i++)
int n,m,a[200005],ans=0;
void dg(int sum,int cnt,int pre)
{
	if(cnt==m)
	{
		ans=max(ans,sum);
		return;
	}
	fr(i,pre,n)dg(sum&a[i],cnt+1,i+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	fr(i,1,n)scanf("%d",&a[i]);
	fr(i,1,n)dg(a[i],1,i+1);
	printf("%d",ans);
	return 0;
}

