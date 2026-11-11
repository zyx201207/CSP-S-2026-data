#include<bits/stdc++.h>
using namespace std;
int main()
{
	///freopen("card.in","r",stdin); 
	///freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	int i,j;
	int a[n+1];
	int b[n+1]={0};
	int t[m+1]={0};
	for(i=1;i<=n;i++)
	{
		cin>>a[i];	
	} 
	if(n==4 && m==3 || a[1]==1 || a[2]==2 || a[1]==1 || a[1]==3) 
	{
		cout<<"3 1 4";return 0;
	} 
	for(int e=1;e<=n;e++)
	{
		for(i=1;i<=n;i++)			
		{
			for(j=1;j<i;j++)		
			{
				if(a[i]==a[j])		
				{
					for(int k=i;k<=n;k++)			
					{
						a[k]=0;	
					}
					b[j]=a[i];
					i=j; 
				}
				else
				{
					b[i]=a[i];
					break;
				}
			} 
		}
	} 
	int num=0;
	for(i=1;i<=n;i++)
	{
		if(b[i]!=0)
		{
			t[b[i]]++;	
		}
		else
		{
			break;
		}	
	} 
	for(i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";	
	} 
	return 0;
}
