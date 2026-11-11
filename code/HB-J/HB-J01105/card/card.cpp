#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int ans[300000]={0};
	int data[500000];
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>data[i];
	}
	
	for(int i=1;i<=n;i++)
	{

		int t[300000]={0};
		int l[500000]={0};
		int s=i;
		for(int j=s;j<=n;j++)
		{
			l[j]=data[j];
			if(t[data[j]]!=0)
			{
				for(int k=t[data[j]];k<j;k++)
				{
					t[l[k]]=0;
					l[k]=0;
				}
			}
			else
			{
				t[data[j]]=j+1;
			}
		}
		for(int s=1;s<=m;s++)
		{
			if(t[s]!=0)
			{
				ans[s]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
