#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],appear[300005];
void turn(int x)
{
	int top=0,s[500005]={},book[300005]={};
	for(int i=x;i<=n;i++)
	{
		if(book[a[i]]==0)
		{
			s[++top]=a[i];
			book[a[i]]=top;
		}
		else
		{
			for(int j=book[a[i]]+1;j<=top;j++)
				book[s[j]]=0;
			top=book[a[i]];
		}
	}
	for(int i=1;i<=top;i++)
		appear[s[i]]++;
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		turn(i);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",appear[i]);
	}
	return 0;
}
