#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in.txt","r",stdin);
	freopen("card.out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int b[100005]={};
	b[n]=n; 
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int s[n]={};
			int k=a[j];
			if(s[k]==1)
			{
				
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i];
	}
}
