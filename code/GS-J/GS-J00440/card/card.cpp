#include<bits/stdc++.h>
using namespace std;
long long int n,m,r,l=-1,ans,a[100111];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			
		}for(int i=1;i<=1;i++)
		{
			if(i==a[i])cout<<n<<' ';
			else cout<<0<<' ';
		}
	}else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			
		}for(int i=1;i<=a[n];i++)
		{
			if(i==a[i])cout<<n<<' ';
			else cout<<0<<' ';
		}
	}

	return 0;
 } 
