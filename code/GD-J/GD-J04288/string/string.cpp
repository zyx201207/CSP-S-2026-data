#include<bits/stdc++.h>
using namespace std;
string c;
int main()
{
	//freopen("string.in","w",stdin);
	//freopen("string.out","r",stdout);
	long long n,num=0;
	cin>>n;
	long long a[n+1];
	char cc[n+1];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>cc[i];
		long long cnt=num;
		num+=a[i];
		for(long long j=cnt;j<num;j++)
		{
			c[j]=cc[i];
		}
	}
	long long cnt=0;
	for(long long i=0;i<num/2;i++)
	{
		if(c[i]!=c[num-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
