#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=-1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxx)maxx=a[i];
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(a[i]<maxx)
		{
			cout<<a[i];
			return 0;
		}
	}



    return 0;
 }
