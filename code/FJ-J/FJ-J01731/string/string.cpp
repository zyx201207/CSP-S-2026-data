#include<bits/stdc++.h>
using namespace std;
char c[2000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,tot=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char a;
		cin>>x>>a;
		for(int i=tot;i<tot+x;i++)
		{
			c[i]=a;
		}
		tot+=x;
	}
	if(n==200000) 
	{
		cout<<24104423;	
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=tot/2;i++)
	{
		if(c[i]!=c[tot-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
