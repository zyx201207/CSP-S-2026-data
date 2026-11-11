#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],t[300010],s[300010];
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
		int num=0;
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]!=0)
			{
				for(int k=t[a[j]];k<j;k++)
				{
					t[a[k]]=0;
				}
				t[a[j]]=j;
			}
			else
			{
				t[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(t[j]!=0)
			{
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<' ';
	}
	
	
	return 0;
} 
