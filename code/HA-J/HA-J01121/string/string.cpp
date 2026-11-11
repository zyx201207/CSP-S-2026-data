#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
char s[20000010];
long long k,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]!=a[i-1])
		{
			f=false;
		}
	}
	if(f==true)
	{
		for(int i=1;i<=n/2;i++)
		{
			if(c[i]!=c[n-i+1])  sum+=a[i];
		}
		cout<<sum;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			while(a[i]--)
			{
				s[++k]=c[i];
			}
		}
		for(int i=1;i<=k/2;i++)
		{
			if(s[i]!=s[k+1-i]) 
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
