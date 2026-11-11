#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
string c[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	if(a[1]-a[n]>=0)
	{
		cout<<a[1]-a[n];
	}
	else
	{
		cout<<a[n]-a[1];
	}
	return 0;
}
