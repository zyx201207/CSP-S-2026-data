#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin)
    freopen("and.out","w",stdout)	
    int n,b=0,m,c;
    
    cin>>n>>m;
    int a[100000];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int i=1;i<=n;i++)
		
		    if(a[i]<a[i+1])
		    {
		        b=a[i];
			    a[i]=a[i+1];
			    a[i+1]=b;
		    }
	}
	for(int i=1;i<=m-1;i++)
	{
		a[i+1]=a[i] & a[i+1];
	}
	cout<<a[m];
	return 0;
}
