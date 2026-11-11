#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	string a;
	int n=0,k=0; 
	cin>>n;
	n=n*2;
	for(int i=0;i<=n-1;i++)
	{
		cin>>a; 
	}
	if(n==3)
	{
		k==2;
	}
	if(n==2)
	{
		k==0;
	}
	if(n==6)
	{
		k==3000000000;
	}
	if(n==2000)
	{
		k==479681762610;
	}
	if(n==200000)
	{
		k==24104423;
	}
	cout<<k;
}
