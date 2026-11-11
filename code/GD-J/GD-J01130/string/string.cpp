#include<bits/stdc++.h>
using namespace std;
long long n;
char a[1000005];
long long b[1000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0,num=0;
	char c[1000005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
		for(int j=sum+1;j<=b[i]+sum+1;j++)
		{
			c[j]=a[i];
		}
		sum+=b[i];
	}
	long long m;
	if(sum%2==1)
	{
		m=(sum+1)/2;
	}
	else
	{
		m=sum/2;
	}
	for(int i=1;i<=m;i++)
	{
		if(c[i]==c[sum-i+1])
		{
			continue;			
		}
		else
		{
			num++;
		}		
	}
	cout<<num<<endl;
	return 0;
}
