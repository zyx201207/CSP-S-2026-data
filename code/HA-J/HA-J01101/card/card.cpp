#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	preopen("card.in","r",stdin);
	preopen("card.out","w",stdout);
	int n,m,t;
	t=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=t-1;i<n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]==a[j-j+1])
			{
				
			}
		}
	}
}
