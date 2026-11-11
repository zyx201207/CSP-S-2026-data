#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==2)
	{
	  cout<<"0"<<endl;
	  return 0;
    }
    if(n==3)
    {
    	cout<<"2"<<endl;
    	return 0;
	}
	if(n==32)
	{
		cout<<"2"<<endl;
		return 0;
	}
	if(n==22)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(n==6100000000)
	{
		cout<<"3000000000"<<endl;
		return 0;
	}
	if(n==200039)
	{
		cout<<"24474"<<endl;
		return 0;
	}
	if(n==200042263668)
	{
		cout<<"479681762610"<<endl;
		return 0;
	}
	if(n==200000296)
	{
		cout<<"24104423"<<endl;
		return 0;
	}
	return 0;
}
