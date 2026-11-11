#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
long long n;
long long a[200050];
char b[200050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(b[1]==b[2] || a[1]==a[2])
	{
		cout<<0;
		return 0;
	}
	if(a[1]%2==0 && a[2]%2==0)
	{
		cout<<0;
		return 0;
	}
	cout<<abs(a[1]-a[2])/2;
	return 0;
}

