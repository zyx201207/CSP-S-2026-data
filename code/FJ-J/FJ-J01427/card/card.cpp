#include<iostream>
#include<set>
using namespace std;
int n,m,a[500005],lst[300005],ans[300005],d[300005];
multiset<int>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		lst[a[i]]=i;
		d[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=lst[a[i]])
			d[lst[a[i]]]+=d[i];
		else
			ans[a[i]]=d[i],d[i+1]+=d[i];
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
/*
青，出于蓝，而青于蓝，冰，水为之，而寒于水 ……（完了后面忘了） 
If I AK CSP,I will biaobai.
*/
