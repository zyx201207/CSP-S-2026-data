#include <iostream>
#include <cstring>
using namespace std;
int n,m,ans[500500];
int a[500500],p[500500],book[500500];
int pre[500500];
int main()
{
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	if(n>=500&&n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			book[a[i]]++;
		}
		for(int i=1;i<=n-1;i++)
		{
			pre[i]=a[i]+a[i+1];
		}
		for(int i=1;i<=n-1;i++)
		{
			cout<<pre[i];
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(book[a[j]]==1)
				{
					for(int k=p[a[j]]+1;k<=j;k++)
					{
						book[a[k]]=0;
					}
					book[a[j]]=1;
				}
				else
				{
					book[a[j]]++;
					p[a[j]]=j;
				}
				/*for(int j=1;j<=m;j++)
				{
					cout<<book[j]<<" ";
				}
				cout<<endl;*/
			}
			for(int j=1;j<=m;j++)
			{
				if(book[j]!=0)
				{
					ans[j]++;
				}
			}
			memset(book,0,sizeof book);
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
