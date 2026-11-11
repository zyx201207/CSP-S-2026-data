#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200000050000],z,b;
char m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b>>m;
		for(int j=z;j<z+b;j++)
		{
			a[j]=m;
		}
		z+=b;
	}
	for(int i=0;i<z/2;i++)
	{
		if(a[i]!=a[z-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
