#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std; 
using ll=long long;
const int maxn=2e5+5;
int a[maxn],ans;
int n, m;
bool flag[maxn];
void sol(int lev,int tmp[],int pos)
{
	if(lev>m)
	{
		int x=tmp[1]&tmp[2];
		for(int i=2;i<=m;i++)
		{
			x=x&tmp[i];
		}
		ans=max(ans,x);
		return ;
	}
	for(int i=pos;i<=n;i++)
	{
		if(flag[i]) continue;
		flag[i]=1;
		tmp[lev]=a[i];
		sol(lev+1,tmp,i);
		flag[i]=0;
	}
}
int tem[maxn];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sol(1,tem,1);
	printf("%d\n",ans);
	return 0;
}

