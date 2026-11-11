#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
struct node{
	int w,b;
}book[300005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		memset(book,0,sizeof book);
		for(int j=i;j<=n;j++)
		{
			if(book[a[j]].b==0)
			{
				book[a[j]].b++;
				book[a[j]].w=j;
			}
			else
			{
				for(int k=book[a[j]].w+1;k<=n;k++)
				{
					book[a[k]].w=0;
					book[a[k]].b=0;
					book[a[j]].b++;
					book[a[j]].w=j;
				}
			}
		}
		for(int j=1;j<=m;j++) ans[j]=book[j].b;
	}
	for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
	return 0;
}
