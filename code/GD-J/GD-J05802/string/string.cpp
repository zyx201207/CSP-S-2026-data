#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s[sum+j]=c;
		}
		sum+=a;
	}
		
	long long cnt=0;
	for(long long i=1;i<=sum/2;i++)
	{
		if(s[i]!=s[sum-i+1])cnt++;
	}
	cout<<cnt;
	

	return 0;
}
