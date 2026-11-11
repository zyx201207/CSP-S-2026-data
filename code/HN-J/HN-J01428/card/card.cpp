#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long list_n[n]={};
	long list_result[m+5]={};
	long table[n]={};
	int ce[m+5]={};
	for(int i=0;i<n;i++)
	{
		cin>>list_n[i];
	}
	for(int i=0;i<m+5;i++)
	{
		ce[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			table[j]=-1;
		}
		for(int j=i;j<n;j++)
		{
			table[j]=list_n[j];
			if(ce[table[j]]==-1)
			{
				ce[table[j]]=j;
			}else{
				for(int f=ce[table[j]];f<j;f++)
				{
					//cout<<table[f]<<endl;
					table[f]=-1;
				}
				ce[table[j]]=j;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(table[j]!=-1)
			{
				list_result[table[j]]++;
			}
		}
	}
	for(int i=1;i<m+1;i++)
	{
		cout<<list_result[i]<<' ';
	}
	return 0;
}
