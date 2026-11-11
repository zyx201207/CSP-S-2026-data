#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e5+5;
int arr[N],table[N],book[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(table,0,sizeof table);
		int len=0;
		for(int j=i;j<=n;j++)
		{
			int card=arr[j],flag=0;
			for(int k=len-1;k>=0;k--)
			{
				if(card==table[k]) 
				{
					len=k+1;
					flag=1;
				}
			}
			if(flag==0) 
			{
				table[len]=card;
				len++;
			}
		}
		for(int j=0;j<len;j++)
		{
			book[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<book[i]<<' ';
	}
	cout<<endl;
	return 0;
}
