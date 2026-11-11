#include<bits/stdc++.h>
#define ll long long
using namespace std;
int find(int a[],int len,int b)
{
	int k=0;
	for(int i=1;i<=len;i++)
	{
		if(a[i]==b)
		{
			k=i;
			break;
		}
	}
	return k;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans[m]={0};
	for(int i=1;i<=n;i++)
	{
		int b[n]={0},len=0;
		for(int j=i;j<=n;j++)
		{
			
			if(find(b,len,a[j])==0)
			{
				len++;
				b[len]=a[j];
			}
			else
			{
				len=find(b,len,a[j]);				
			}
		}
		for(int i=1;i<=len;i++)
		{
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
