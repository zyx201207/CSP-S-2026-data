#include<bits/stdc++.h>;
using namespace std;

int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,sum=0,jjs=0;
	long long s[10000005],sumlb[1000000005];
	cin>>a>>b;
	for(int i=1;i<=a;i++) 
	{
		cin>>s[i];
	}
	for(int i=1;i<=a;i++)
	{
		jjs++;
		sumlb=(int)s[i] & (int)s[i+1];
	}
	for(int i=1;i<=jjs;i++)
	{
		cout<<c[i]
	}
	cout<<(int)sum;
	return 0;
}
