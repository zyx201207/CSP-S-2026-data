#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b[1000],cnt=0,c[1000],n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		b[i]=a;
	}
	for(int j=1;j<=n;j++)
	{
		if(b[j]>b[1])
		{
			b[j]=b[1];
			b[j-1]=b[j];
		}
		else
		{
			b[j]=b[j];
		}
	}
	for(int l=1;l<=n;l++)
	{
		c[l]=b[l]-b[l-1];
	}
	for(int q=1;q<=n;q++)
	{
		if(c[q]<c[1])
		{
			c[q]=c[1];
			c[q-1]=c[q];
		}
		else
		{
			c[q]=c[q];
		}
	}
	for(int k=1;k<=n;k++)
	{
		s=s-c[k];
		cnt++;
		if(s<0)
		{
			cout<<cnt-1;
			break;
		 } 
	}
	cout<<cnt; 
	return 0;
}
