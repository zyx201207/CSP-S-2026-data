#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m=0;
	int a=0;
	int o=0;
	cin>>a;
	int n=0;
	cin>>n;
	int arr[100008]={};
	for(int i=0;i<a;i++)
	{
		cin>>arr[i];
	}
	m=arr[0];
	for(int i=1;i<a;i++)
	{
		if(m<arr[i])
		{
			o=m;
			m=arr[i];
		}
		else
		{
			o=arr[i];
		}
	}
	cout<<o;
	return 0;
}
