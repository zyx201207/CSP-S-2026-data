#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string m;
	long long a;
	int n;
	char c[10];
	cin>>n;
	long long x=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>c[0];
		for(long long j=1;j<=a;j++)
		{
			m[x]=c[0];
			x++;
		}
	}
	x--;
	long long s=0;
	for(long long i=1;i<=x/2;i++)
	{
		if(m[i]!=m[x])
		{
			s++;
			x--;	
		}
	}
	cout<<s;
	return 0;
}