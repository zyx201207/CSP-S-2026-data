#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
char b[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0,t;
	bool f=1;
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i]/2;
	}
	for(long long i=2;i<=t;i++)
	{
		if(b[i] != b[i-1]) f=0;
		
	}
	if(f == 1) cout<<0;
	else cout<<sum;
	return 0;
}
