#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,MAXN=2147483647;
int n,m,ans;
int a[N];
bool book[N],isA=1,isB=1;
void dfs(int sum,int step)
{
	if(step==m) 
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++) 
	{
		if(book[i]) continue;
		book[i]=1;
		if(sum==-1) dfs(a[i],step+1);
		else dfs(sum&a[i],step+1);
		book[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]!=i-1) isB=0;
		if((a[i]&MAXN)!=a[i]) isA=0;
	}
	sort(a+1,a+1+n);
	if(isA) printf("%d",a[n-m+1]);
	else 
	{
		dfs(-1,0);
		printf("%d",ans);
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
