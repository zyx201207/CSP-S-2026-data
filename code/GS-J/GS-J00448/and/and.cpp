#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[1005][1005];
    for(int i=1;i<=n;i++) 
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j];
		}
	}
}
