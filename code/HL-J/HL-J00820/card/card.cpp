#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,n,g,c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]==i) g=1;
		}
		if(g==1) c++;
		g=0;
	}
	cout<<c;
	return 0;      
}