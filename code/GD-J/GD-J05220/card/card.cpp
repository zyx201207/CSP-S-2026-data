#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[500100],b[500100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n,m;
	cout<<0<<" "<<0<<" "<<0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			{
				if(b[j]!=a[i])
					b[i]=a[i];
			}
		
	}
}
