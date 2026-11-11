#include <bits/stdc++.h> 
using namespace std;
struct f{
	int a;
	char b;
}u[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=1,k=0;
	char l1[10000001],l2[10000001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i].a>>u[i].b;
		
	}
	
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=u[i].a;j++)
		{
			
			l1[x]=u[i].b;
			x++;
		}
	}
	x=1;
	for(int i=n;i>=n/2;i--)
	{
		for(int j=1;j<=u[i].a;j++)
		{
			
			l2[x]=u[i].b;
			x++;
		}
	}
	for(int i=1;i<=x;i++)
	{
		if(l1[i]!=l2[i])
		{
			k++;
		}
	}
	cout<<k;
	return 0; 
}
