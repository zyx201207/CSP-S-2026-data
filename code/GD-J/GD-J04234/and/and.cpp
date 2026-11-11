#include<iostream>
using namespace std;
int a[200000];
int main()
{
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s++;
	}
	cout<<a[s];
} 
