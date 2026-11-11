#include<bits/stdc++.h>
using namespace std;
int m,n;
int d[20005];
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int y=0;y<=n;y++)
	{
		cin>>d[y];
	}
	int sd=0;
	for(int f=0;f<=n;f++)
	{
		for(int k=0;k<=n;k++)
	{
		int u=d[f] and d[k];
		sd=max(sd,u);
	}
		
	}
		cout<<sd;
		
	
	
	
}
