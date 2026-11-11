#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[]={}; 
int k[]={};
int a[]={}; 
int t[]={};
int x[]={}; 
int y[]={};
int r;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i;i<=n;i++)
	{
		cin<<k[i];
	}
	for(int i;i<=1+2*k;i++)
	{
		for(int j;j<=i;j++)
		{
			cin>>a[j];
			cin>>t[j];
		}
	}
	for(int i;i<=q;r++)
	{
		cin>>r;
	}
	for(int i;i<r+n+2;i++)
	{
		cin>>x[i];
		cin>>y[i];
	}
	
	return 0;
}
