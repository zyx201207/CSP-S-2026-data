#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a;
	char b;
	string c;
	char x;
	char y;
	long long cnt=0;
	for(int i=0;i<n;i++) 
	{
		cin>>a;
		cin>>b; 
		for(int j=0;j<a;j++)
			c+=b;
	}
	long long t=c.size();
	for(long long i=1;i<n;i++)
	{
		for(long long k=0;k<t/2;k++) 
			x=c[k];
		for(long long j=t;j>=t/2+1;j--) 
			y=c[j];
		if(x!=y)
			cnt++;
	}
	cout<<cnt;
	return 0;
 } 
