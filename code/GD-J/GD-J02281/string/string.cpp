#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	cin>>n;
	string a,b;
	for(int i=1;i<=n;i++)
	{
	cin>>x>>b;
	for(int j=1;j<=x;j++)
	{
	a+=b;
	}
	}
	long long len=a.size(),cnt=0;
	for(long long i=0;i<len/2;i++)
	{
	if(a[i]!=a[len-i-1])
	{
	cnt++;
	}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
