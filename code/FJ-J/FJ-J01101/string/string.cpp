#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	string a,b,c;
	long long n,aa,d=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>aa>>b;
		for(int ii=1;ii<=aa;ii++)
		{
			a+=b;
		}
	}
	for(int i=1;i<=a.length()/2;i++)
	{
		b=a[i-1];
		c=a[a.length()-i-1];
		if(b!=c) d++;
	}
	cout<<d;
	return 0;
}
