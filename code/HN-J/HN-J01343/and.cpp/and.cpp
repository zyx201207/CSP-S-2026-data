#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(n==1)
		{
			cout<<n; 
		}
		for(int j=2;j<=n;j++) 
		{
			if(a[i]==a[j])
			{
			cout<<a[i];	
			break;
			}
		}
	 } 
	 return 0;
}
