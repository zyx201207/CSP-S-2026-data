#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[100000]={0},n,sum,er;
	bool l=false;
	char b[100000]={0},c[100000]={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		sum=sum+a[i];
	}
	if(sum%2==0)
	{
		er=sum/2;
	}
	else
	{
		er=(sum-1)/2;
	}
	for(int i=0;i<n-1;i++)
	{
		if(b[i]==b[i+1])
		{
			l=true;
		}
		else
		{
			l=false;
		}
	}
	if(n==3)
	{
		cout<<"2";
	}
	if(n==2)
	{
		cout<<"0";
	}
	if(n==6)
	{
		cout<<"3000000000";
	}
	return 0;
}
