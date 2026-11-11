#include<bits/stdc++.h>
using namespace std;
int main()
{
	///freopen("string.in","r",stdin); 
	///freopen("string.out","w",stdout); 
	long long n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	char c[1000000];
	int num=0;
	int a;
	char b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=num+1;j<=a+num;j++)
		{
			c[j]=b;
		}
		num+=a;
	}
	int d=num/2;
	int sum=0;
	for(int i=1;i<=d;i++)
	{
		if(c[i]!=c[num-i]) sum++; 
	}
	cout<<sum;
	return 0;
}
