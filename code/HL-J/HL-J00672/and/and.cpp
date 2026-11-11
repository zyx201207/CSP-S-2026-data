#include<bits/stdc++.h>
using namespace std;
int a[2005];
int  c[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int k=0;
	int min=-9999999999;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
			k=a[(i+9)/2+3];
	}

		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
		
	    c[i]=a[i]&a[j];
	    
	}

	for(int i=0;i<n;i++)
	{
		
		if(c[i]>min)
		{
			min=max(c[i],min);
	}
	
	}
	min=int(min)%100;
	cout<<a[k];
	}
}

