#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],sum=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=a[i];j<=m;j++)
		{
			sum=max(a++);	
		}
		sum++; 
	}
	cout<<sum;
	return 0;	
} 
