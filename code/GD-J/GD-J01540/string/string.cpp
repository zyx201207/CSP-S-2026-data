#include<bits/stdc++.h>
using namespace std;
char s[200000000001000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,sum1=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char a;
		scanf(" %d %c",&x,&a);
		for(long long j=1;j<=x;j++)
		{
			s[sum1+i]=a;
		}
		sum1==x; 
	}
	for(long long i=0;i<sum1/2;i++)
	{
		if(s[i]!=s[sum1-1])
		sum++;
	}
	cout<<sum;
}
