#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20,M=3e5+20;
int n,m,loa[M],ans[M];
struct card
{
	int a,nex;
} a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
	} 
	for(int i=n;i>=1;i--)
	{
		if(loa[a[i].a]) a[i].nex=loa[a[i].a];
		else loa[a[i].a]=i;
	}
	//输入 nex下一次ai出现位置
	for(int i=1;i<=n;i++) //n局游戏开始位置 
	{
		for(int j=i;j<=n;)
		{
			if(a[j].nex)
			{
				j=a[j].nex;
				continue;
			}
			ans[a[j].a]++;
			j++;
		} 
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
