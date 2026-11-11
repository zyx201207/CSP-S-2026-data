#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
struct qujian
{
	int L,R,num;
}qu[N];
bool flag[M];
int a[N],lst[M];
int n,m;
int cnt=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag2=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) flag2=false;
	}
	if(flag2)
	{
		int cnt2=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
				printf("%d ",cnt2);
			cnt2++;
		}
		printf("%d\n",cnt2);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[a[i]])
		{
			flag[a[i]]=true;
			lst[a[i]]=i;
		}
		else
		{
			qu[cnt].L=lst[a[i]];
			qu[cnt].R=i;
			qu[cnt++].num=a[i];
			lst[a[i]]=i;
		}
	}
/*	for(int i=1;i<cnt;i++)
	{
		
	}*/
	return 0;
}

