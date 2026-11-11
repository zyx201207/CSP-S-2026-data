#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int num[300010];
int kind[300010];
int ans[300010],tail;
bool b[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=200)
	{
		for(int i=1;i<=n;i++)
		{
			memset(num,0,sizeof(num));
			memset(kind,0,sizeof(kind));
			memset(b,0,sizeof(b));
			for(int j=i;j<=n;j++)
			{
				if(num[a[j]]!=0)
				{
					if(b[num[a[j]]]==0)
					{
						for(int l=num[a[j]];l<j;l++)
						{
							if(b[l]==0) kind[a[l]]--;
							b[l]=1;
						}
					}
					num[a[j]]=j;
					kind[a[j]]++;
				}
				else
				{
					kind[a[j]]++;
					num[a[j]]=j;
				}
			}
			for(int j=1;j<=m;j++)
			{
				if(kind[j]>0) ans[j]++;
			}
		}
	}
	else 
	{
		for(int i=1;i<=n;i++)
		{
			tail=0;
			memset(num,0,sizeof(num));
			memset(kind,0,sizeof(kind));
			memset(b,0,sizeof(b));
			for(int j=i;j<=n;j++)
			{
				if(num[a[j]]>tail||num[a[j]]==0)
				{
					tail++;
					num[a[j]]=tail;
					kind[tail]=a[j];
				}
				else
				{
					tail=num[a[j]];
				}
			}
			for(int j=1;j<=tail;j++)
			{
				ans[kind[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
