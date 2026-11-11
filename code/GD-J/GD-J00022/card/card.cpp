#include<bits/stdc++.h>
using namespace std;
int ans;
int n,m;
int a[500005];
int st[500005];
int anser[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int top=0;
		map<int,int>mp;
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]]!=0)
			{
				while(top>mp[a[j]])
				{
					mp[st[top]]=0;
					top--;
				}
			}
			else{
				st[++top]=a[j];
				mp[a[j]]=top;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(mp[j]!=0)
			{
				anser[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",anser[i]);
	}
	
	return 0;
}
