#include <bits/stdc++.h>
using namespace std;
int a[500005];
int vis[500005];
int b[500005];
int s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=i;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=j;
				b[l]=a[j];
				l++;
			}
			else
			{
				l=vis[a[j]]+1;
			}
		}
		for(int j=i;j<=l;j++)
		{
			s[b[j]]++;
		}
		for(int i=1;i<=m;i++)
		{
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
