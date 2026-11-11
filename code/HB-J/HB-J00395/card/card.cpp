#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[300005],book[500005];
int top;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof book);
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=top;k++)
			{
				if(book[k]==a[j])
				{
					while(top>=k)top--;
					break;
				}
			}
			book[++top]=a[j];
		}
		for(int i=1;i<=top;i++)
		{
			ans[book[i]]++;
		}	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}				
	return 0;
}	
