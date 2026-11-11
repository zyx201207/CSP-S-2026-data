#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen(card.in,"r",studin);
	freopen(card.out,"w",studout);
	
	int n,m,a[10000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i]==a[j])
			{
			    for(int k=j;k<=i;k++)
			    {
			    	a[k]=0;
				}
				a[j]=a[i];
				i=j;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0)
		{
			cout<<"";
		}
		cout<<a[i];
	}
	return 0;
}
