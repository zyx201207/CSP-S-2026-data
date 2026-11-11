#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int max=0;
	 for(int i=0;i<n;i++)
	 {
	 	cin>>a[i];
	 }
	 for(int a=n;a>0;a--)
	 {
	 	for(int b=0;b<a;b++)
	 	{
	 		max=0;
	 		if(a[b]>max)
	 		{
	 			max=a[b];
			 }
			 
			 
		 }
		 
	 }
 } 
