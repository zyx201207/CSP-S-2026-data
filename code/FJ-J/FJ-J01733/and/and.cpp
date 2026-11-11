#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int a[200010],pmax=0;
int n,m;
void dfs(int idx,int sum,int k)
{
	if(idx>n&&k<m) return ;
	if(k==m) {
		ans=max(ans,sum);
		return ;
	}
	dfs(idx+1,sum&a[idx],k+1);
	if(k==0) dfs(idx+1,a[idx+1],k);
	else dfs(idx+1,sum,k);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==n)
	{
		for(int i=1;i<=n;i++)
			a[1]&=a[i];
		printf("%d\n",a[1]);
		return 0;
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		printf("%d\n",a[n]);
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				pmax=max(pmax,a[i]&a[j]);
		printf("%d\n",pmax);
		return 0;
	}
	dfs(1,a[1],0);//È«ÅÅÁÐ 
	printf("%d\n",ans);
	return 0;
}
