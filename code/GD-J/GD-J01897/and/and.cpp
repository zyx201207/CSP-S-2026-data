#include <bits/stdc++.h>
using namespace std;
int main(){

	int n,m;
	cin>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int k=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	cout<<a[m];
	return 0;
} 
