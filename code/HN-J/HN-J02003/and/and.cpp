#include<bits/stdc++.h>
int n,m,a[200000],answer;
void dfs(int counter,int deep,int chosen)
{
	if(counter<=answer)
		return;
	if(chosen==m)
	{
		answer=std::max(answer,counter);
		return;
	}
	if(n-deep>m-chosen)
	{
		dfs(counter&a[deep],deep+1,chosen+1);
		dfs(counter,deep+1,chosen);
	}
	else
		dfs(counter&a[deep],deep+1,chosen+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	dfs(2147483647,0,0);
	printf("%d",answer);
	return 0;
}
