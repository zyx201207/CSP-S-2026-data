#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,a[200005],x[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]<<" "; 
	}
	for(int j=0;j<n;j++)
	{
	    for(int i=0;i<a[i];i++)
	    {
	    	int x[i]=a[i]%2;
		    a[i]=a[i]/2;
		}
	}
	return 0;	    
} 
