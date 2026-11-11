#include<bits/stdc++.h>
using namespace std;
long long n,s;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long f=0;
	for(int i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		f+=x;
		char b;
		cin>>b;
		for(int j=1;j<=x;j++)
		{
			a+=b;
		}
	}
	if(f%2==0)
	{
		for(int i=0;i<f/2;i++)
		{
			for(int j=f/2;j<f;j++)
			{
				if(j-i==f/2 && a[j]!=a[i])
				{
					a[j]=a[i];
					s++;
				}
			}
		}
		cout<<s;
		return 0;
	}
	else
	{
		for(int i=0;i<f/2;i++)
		{
			for(int j=f/2+1;j<f;j++)
			{
				if(j-i==f/2+1 && a[j]!=a[i])
				{
					a[j]=a[i];
					s++;
				}
			}
		}
		cout<<s;
		return 0;
	}
	return 0;
} 
