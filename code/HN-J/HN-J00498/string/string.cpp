#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s,ans=0;
	cin>>n;
	string z,a="";
	for(int i=1;i<=n;i++)
	{
		cin>>s>>z[i];
		for(int j=1;j<=s;j++)a[i]=a[i]+z[i];
	}
	for(int i=0;i<=a.size()/2;i++)
	{
		if(a[i]!=a[a.size()-i])
		{
			a[i]=a[a.size()-i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
