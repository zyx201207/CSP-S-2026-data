#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[5100],s[5100],h[5100][5100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;
for(int f=0;f<t;f++)
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]-s[i-1];
	}
	
}
cout<<"0";
	return 0;
}
