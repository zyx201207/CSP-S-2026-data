#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[500005],num[500005];
int top,botton,f;

void su(int t)
{
	for(int i=t;i<n;i++)
	{
	if(top==botton)
		{
			ans[top++]=a[i];
		}
		else
		{
			for(int j=0;j<top;j++)
		{
		  if(a[i]==ans[j])
		  {
		  	top=j;
		  	ans[top++]=a[i];
		  }
		  else
		  {
		  	ans[top++]=a[i];
		  }
		}
		}
		
	}
}
void shu()
{
		for(int j=1;j<=m;j++)
		{
			for(int i=0;i<top;i++)
	     {
		   if(ans[i]==j)
		   num[j]++;
		  }
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		su(i);
		shu();
		top=0;
		botton=0;
	}
  for(int i=1;i<=m;i++)
  {
  	cout<<num[i]<<" ";
  }
}
