#include<iostream>
using namespace std;
long long ans,num[600000],b[600000],n,m,e,y;
void s(int a[],int k,int i)
{
	for(int j=n;j>=i;j--)
	{
		if(a[j]==k)
		{
			b[k]++;
			
			k=a[j+1];
			i=j+1;
		}
		
	}
	int x=n-i;
	if(x<=m&&i==n+1)
	{
		e=i-1;
		return;
	}
	else
		s(a,k,i);
	
	
}
int main()
{
	freopen("card.in","r",stdin);	
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		int k=num[i];
		int a[60000]={0};
		for(int j=i;j<=n;j++)
		{
			a[j]=num[j];
		}
		e=i;
		s(a,k,e);
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
} 
